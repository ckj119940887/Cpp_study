#include <iostream>
using namespace std;

/*
静态成员无所谓被继承，静态成员全局只有一份，被所有类共享
*/

class Base
{
public:
    static int b_;
};

int Base::b_ = 100;

class Derived : public Base
{

};

int main()
{

    cout << Base::b_ << endl;
    cout << Derived::b_ << endl;

    return 0;
}