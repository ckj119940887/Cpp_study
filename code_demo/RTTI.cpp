#include <iostream>
using namespace std;

/*
RTTI:runtime type information 

dynamic_cast: 要用在具有多态的继承关系上，即基类有虚函数
typeid:
type_info:
*/

class Shape
{
public:
    virtual void Draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void Draw()
    {
        cout << "Circle ..." << endl;
    }
};

class Square: public Shape
{
public:
    void Draw()
    {
        cout << "Square ..." << endl;
    }
};

int main()
{
    Shape* p;
    Circle c;

    p = &c;
    p->Draw();

    if(dynamic_cast<Circle*>(p)) {
        cout << "p is point to a Circle object" << endl;
        Circle* cp = dynamic_cast<Circle*>(p); //安全的向下转型
        cp->Draw();
    }
    else if(dynamic_cast<Square*>(p)) {
        cout << "p is point to a Square object" << endl;
        Square* cp = dynamic_cast<Square*>(p);
    }

    cout << typeid(*p).name() << endl;
    cout << typeid(Circle).name() << endl;

    return 0;
}