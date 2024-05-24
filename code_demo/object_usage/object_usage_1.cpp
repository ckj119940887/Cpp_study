#include <iostream>
using namespace std;

/*
静态成员变量：
用全局变量会破坏数据的封装，用类的静态成员可以处理该问题。
非static 数据成员存于类类型的每个对象中，static成员独立于该类的任意对象存在。
*/

/*
访问静态成员变量和函数时，尽量使用CountedObject::count_和CountedObject::TestStaticFunc()
来访问。
*/

class CountedObject
{
public:
    CountedObject();
    ~CountedObject();

    void TestFunc() {
        cout << "TestFunc" << endl;
    }

    static void TestStaticFunc() {
        //静态成员函数不能访问非静态成员变量，非静态成员函数可以访问静态成员
        //静态成员函数没有this指针，所以没法访问非静态成员变量
        //静态成员函数不能访问非静态成员函数
        //cout << y_ << endl; //报错
        //TestFunc(); //报错
    }

    //静态成员的引用性说明
    //可以是私有的，此时需要共有接口来访问
    static int count_;
    static const int test_;
    int y_;
};

// 静态成员的定义性说明，这个必须是这样的
// 注意这里不能再加static了，否则会报错
// 初始化也是在类的外部进行初始化，不能在类内进行初始化
int CountedObject::count_ = 100;
const int CountedObject::test_ = 0;

CountedObject::CountedObject() {
    ++count_;
}

CountedObject::~CountedObject() {

}

int main(int argc, char** argv) {
    cout << CountedObject::count_ << endl;

    CountedObject c1;
    cout << CountedObject::count_ << endl;

}