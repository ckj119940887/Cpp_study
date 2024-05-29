#include <iostream>
using namespace std;

class Noncopyable
{
protected:
    Noncopyable() {}
    ~Noncopyable() {}
private:
    Noncopyable(const Noncopyable& other);
    const Noncopyable& operator=(const Noncopyable other);
};

// 使用私有继承，只继承实现，不继承接口
class Parent : private Noncopyable
{

};

int main()
{
    Parent p1;
    //下面语句会报错
    //首先会调用Parent拷贝构造函数，Parent构造函数又调用Noncopyable的拷贝构造函数
    //也是禁止拷贝的,要拷贝构造子类对象，先要拷贝构造基类对象
    //但Noncopyable拷贝构造函数是private，不能访问
    //Parent p2(p1);

    /*
    但是如果在Parent类中给出如下实现，则拷贝构造可以进行
    Parent()
    {

    } 
    Parent(const Parent& other)
    {

    }
    此时，我们重写了基类的默认构造函数和拷贝构造函数。
    这里有个点需要注意，只要提供了构造函数(不管什么类型的构造函数，将不会再提供默认拷贝构造函数)。
    因此这里需要提供默认构造函数，不然会报错，因为基类中也有默认构造函数。
    */

    /*
    上述写法很不规范，没有调用基类的构造函数。 
    默认构造函数会自动调用基类的默认构造函数，此时，可以省略。
    Parent()
    {

    } 
    Parent(const Parent& other) : Noncopyable(other)
    {

    }
    此时拷贝构造不可以进行。 
    */

    return 0;
}