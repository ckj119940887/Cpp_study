#include <iostream>
using namespace std;

/*
不能自动继承的成员函数：
构造函数
析构函数
=运算符
*/

/*
声明构造函数时，只需要对类中新增成员进行初始化，对继承来的基类成员的初始化(调用基类构造函数完成).
派生类的构造函数需要给基类的构造函数传递参数。

派生类构造次序：
1.基类构造函数
2.派生类中的对象成员构造函数
3.派生类中的自身变量构造函数

如果派生类的对象成员没有默认构造函数，需要在构造函数的初始化列表中进行构造
*/

/*
友元关系不能被继承
A时B的友元类、C是A的派生类，那么C不是B的友元类

友元关系是单向的

友元关系是不能被传递的
A时B的友元类、B是C的友元类，那么A不是C的友元类
*/

class ObjectB
{
public:
    ObjectB(int b) : objb_(b)
    {
        cout << "ObjectB ..." << endl;
    }
    ~ObjectB()
    {
        cout << "~ObjectB ..." << endl;
    }
    int objb_;
};

class Base
{
public:
    Base(int b) : b_(b), objb_(100)
    {
        cout << "Base ..." << endl;
    }

    // 在拷贝构造函数中也需要对没有默认构造函数的对象进行构造
    Base(const Base& other) : objb_(other.objb_), b_(other.b_)
    {

    }

    ~Base()
    {
        cout << "~Base ..." << endl;
    }
    int b_;
    ObjectB objb_;
};

class Derived : public Base
{
public:
    Derived(int d, int b) : d_(d), Base(b)
    {
        cout << "Derived ..." << endl;
    }

    // 这里使用Base的拷贝构造函数进行构造
    Derived(const Derived& other) : d_(other.d_), Base(other)
    {

    }

    ~Derived()
    {
        cout << "~Derived ..." << endl;
    }
    int d_;
};

int main()
{
    Derived d(100, 10);
    cout << d.d_ << d.b_ << endl;
    return 0;
}