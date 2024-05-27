#include<iostream>
using namespace std;

//对于一个没有任何接口的类，如果想将它定义成抽象类，只能将析构函数声明为纯虚函数。
//通常情况下，纯虚函数不需要实现。例外是，纯虚析构函数要给出实现。
class Base
{
public:
    virtual ~Base() = 0;
};

Base::~Base()
{

}

class Derived : public Base
{

};

int main()
{
    Derived d;
    return 0;
}