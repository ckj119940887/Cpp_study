#include <iostream>
using namespace std;

class Integer
{
public:
    Integer(int n);
    ~Integer();
    void Display();
    //前置++运算符重载
    Integer& operator ++();
    //friend Integer operator ++(Integer &i);
    //后置++运算符重载
    Integer operator ++(int x);
    //friend Integer operator ++(Integer &i, int x);

    //类型转换运算符重载，与类型转换构造函数相反
    //类型转换运算符是将类类型转换为普通类型，函数原型： operator 类型名();
    //只能以成员函数的方式来重载，不用指定返回类型(其实已经指定了)
    //类型转换构造函数是将普通类型转换为类类型
    operator int();

private:
    int n_;
};

Integer::Integer(int n) : n_(n)
{

}

Integer::~Integer()
{

}

void Integer::Display()
{
    cout << n_ << endl;
}

Integer& Integer::operator ++()
{
    ++ this->n_;
    return *this; 
}

Integer Integer::operator ++(int x)
{
    //需要用临时对象
    Integer tmp(n_);
    n_++;
    return tmp;
}

Integer::operator int()
{
    return this->n_;
}

int add(int x, int y)
{
    return x + y;
}

int main(int argc, char** argv) {

    Integer i(100);
    //这里会将类类型先转化为int，然后再参与运算
    cout << add(i, 100) << endl;

    return 0;
}