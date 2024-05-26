#include <iostream>
using namespace std;

/*
友元是一种允许非类成员函数访问类的非公有成员的一种机制。
友元函数：把一个函数指定为类的友元。
友元类：把一个类指定为另一个类的友元。

友元函数在类作用域外定义，但需要在类体中进行说明。
友元函数不受权限关键字的限制。
friend 类型 友元函数名(参数列表)
*/

/*
友元关系是单向的，A是B的友元类，并不代表B是A的友元类。
友元关系是不能传递的，A是B的友元类，B是C的友元类，并不代表A是C的友元类。
友元关系是不能继承的，A是B的友元类，C继承自A，并不代表C是B的友元类。
*/

class Point
{
    friend double Distance(const Point& p1, const Point& p2);
public:
    Point(int x, int y) : x_(x), y_(y) 
    {

    }
private:
    int x_;
    int y_;
};

// 友元函数不是类的成员函数，所以不需要Point::
double Distance(const Point& p1, const Point& p2)
{
    return 0;
}

class TV
{
    friend class TVController;
public:
    TV(int volumen, int channel) : volumen_(volumen), channel_(channel)
    {

    }
private:
    int volumen_;
    int channel_;
};

class TVController
{
public:
    void VolumenUp(const TV& tv)
    {
        int  x = tv.volumen_;
    }
    void VolumenDown(const TV& tv)
    {

    }
    void ChannelUp(const TV& tv)
    {

    }
    void ChannelDown(const TV& tv)
    {

    }
};

int main(int argc, char** argv) {

    return 0;
}