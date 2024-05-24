#include <iostream>
using namespace std;

/*
单例模式，保证一个类只有一个实例，并提供一个全局访问点。
禁止拷贝。
*/

class Singleton
{
public:
    // 作为全局唯一的访问点
    static Singleton* GetInstance()
    {
        if(instance_ == NULL)
            instance_ = new Singleton;
        return instance_;
    }
    //析构函数不会被自动调用，解决方法就是再提供一个内嵌的类Garbo，这种使用内嵌类的方法可以保证是线程安全的
    /*
    第二种方法更加简单，但是不是线程安全的，就是使用引用
    static Singleton& GetInstance()
    {
        //使用static创建一个局部静态对象，然后全局就这一份，每次访问的都是这一个
        //因为是局部静态对象，所以最后消亡的时候会调用析构函数
        //但是在main函数中定义类对象的时候需要定义引用，如Singleton& s1 = Singleton::GetInstacne();
        static Singleton instance; 
        return instance;
    }
    */
   //第三那种方式是使用auto_ptr智能指针。
    ~Singleton() {
        cout << "~Singleton" << endl;
    }
    class Garbo
    {
    public:
        ~Garbo()
        {
            if(Singleton::instance_ != NULL)
                delete instance_;
        }
    };
private:
    //禁止拷贝构造函数，不然，Singleton s4(*s2)会调用拷贝构造函数;
    //直接将拷贝构造函数设置成private的。同时不提供任何实现。
    Singleton(const Singleton& other);
    //可以将赋值操作也禁止掉
    Singleton operator=(const Singleton& other);
    Singleton();
    static Singleton* instance_;

    // 该类对象在生命期结束时自动调用Garbo中的析构函数,进而自动调用~Singleton析构函数
    static Garbo garbo_;
};

Singleton* Singleton::instance_;
Singleton::Garbo Singleton::garbo_;

int main(int argc, char** argv) {
    // Singleton s1; // 报错，构造函数是私有的，无法在main中进行访问

    // 两次对GetInstance的调用返回的是同一个instance
    Singleton *s2 = Singleton::GetInstance();
    Singleton *s3 = Singleton::GetInstance();

    return 0;
}