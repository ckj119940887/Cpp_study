#include <iostream>
using namespace std;

/*
组合(has-a):希望新类内部具有已存在的类的功能时使用，而不是希望以存在的类作为它的接口。
继承(is-a):希望新类与已存在的类有相同的接口(在此基础上可以增加自己的成员)。
*/

/*
overload : 重载在同一
overwrite : 重写基类函数或变量
override : 覆盖，只针对virtual
*/

class Base
{
public:
    Base() : x_(0)
    {

    }

    int GetBaseX() const
    {
        return x_;
    }

    void Show() const
    {
        cout << "Base::Show ..." << endl;
    }

    int x_;
};

class Derived : public Base
{
public:
    Derived() : x_(100)
    {

    }

    int GetDerivedX() const
    {
        return x_;
    }

    // 重写了基类成员函数
    void Show() const
    {
        cout << "Derived::Show ..." << endl;
    }

    // 重写了基类成员变量
    int x_;
};

int main()
{
    Derived d;
    cout << d.GetDerivedX() << endl;
    d.Show();

    return 0;
}