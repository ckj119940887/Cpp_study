#include <iostream>
using namespace std;

/**
继承方式    类成员特性  派声类成员特性  派声类对象访问
公有继承    public      public      可直接访问
           protected   protected   不可直接访问
           private     不可直接访问  不可直接访问

私有继承    public      private     不可直接访问
           protected   private     不可直接访问
           private     不可直接访问   不可直接访问

保护继承    public      protected    不可直接访问
           protected   protected    不可直接访问
           private     不可直接访问    不可直接访问
*/

/*
类的公有成员函数被称为接口。
公有继承：基类的公有成员函数在派生类中仍然是公有的，即基类的接口仍然是派生类的接口，所以称为接口继承。
实现继承：对于私有、保护继承，派生类不再继承基类的接口，它希望重用基类的实现而已，因而称为实现继承。
*/

class Base
{
public:
    int x_;
protected:
    int y_;
private:
    int z_;
};

class PublicInherit : public Base
{
public:
    void Test()
    {
        x_ = 10; //public属性成员在派生类外可以被直接访问
        y_ = 10; //protected属性成员可以在派生类被直接访问,在派生类外没法被直接访问
        //z_ = 10; //private属性成员只能被成员函数访问
    }
private:
    int a_;
};

class PrivateInherit : private Base
{
public:
    void Test()
    {
        x_ = 10; //public属性和protected属性成员在派生类中还是可以被直接访问
        y_ = 10;
    }
};

int main()
{
    PublicInherit p;
    p.x_ = 0;

    PrivateInherit p2;
    // p2.x_ = 0; //成员只能被成员函数访问，不能被直接访问了

    return 0;
}