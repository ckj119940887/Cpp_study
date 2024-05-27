#include <iostream>
using namespace std;

/*
虚函数：
virtual 函数类型 函数名称(参数列表)
如果一个函数被声明为虚函数，在所有派生类中都是虚函数。
只有通过基类指针或引用调用虚函数才能引发动态绑定。
虚函数不能声明为静态。
*/

class Base
{
public:
    virtual void Fun1()
    {
        cout << "Base::Fun1 ..." << endl;
    }

    virtual void Fun2()
    {
        cout << "Base::Fun2 ..." << endl;
    }

    void Fun3()
    {
        cout << "Base::Fun3 ..." << endl;
    }
};

class Derived : public Base
{
public:
    virtual void Fun1()
    {
        cout << "Derived::Fun1 ..." << endl;
    }

    virtual void Fun2()
    {
        cout << "Derived::Fun2 ..." << endl;
    }

    void Fun3()
    {
        cout << "Derived::Fun3 ..." << endl;
    }
};

int main()
{
    Derived d;
    Base* b;
    
    b = &d;
    b->Fun1(); //Fun1时虚函数，基类指针指向派生类对象，调用的时派生类对象的虚函数
    b->Fun2();
    b->Fun3(); //Fun3非虚函数，根据p指针实际类型来调用相应成员函数

    return 0;
}