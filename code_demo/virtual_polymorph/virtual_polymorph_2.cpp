#include <iostream>
using namespace std;

/*
虚析构函数：
需要通过基类指针删除派生类对象。
如果需要通过基类指针调用对象的析构函数(通过delete这样做是正常的)，并且
被析构的对象是有重要的析构函数的派生类的对象。
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

    Base()
    {
        cout << "Base ..." << endl;
    }

    //如果一个类要作为多态基类，要将析构函数定义成虚函数
    virtual ~Base()
    {
        cout << "~Base ..." << endl;
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

    Derived()
    {
        cout << "Derived ..." << endl;
    }

    ~Derived()
    {
        cout << "~Derived ..." << endl;
    }
};

int main()
{
    Base *p;
    p = new Derived;
    p->Fun1();
    //如果基类中没有将析构函数定义为虚类，则会调用基类的析构函数
    delete p;

    return 0;
}