#include <iostream>
using namespace std;

/*
运算符重载：
不允许发明新的运算符
不能改变运算符操作对象的个数
运算符重载后，优先级和结合性不变
不能重载的运算符, ::, ?:, ., .*, sizeof
*/

/*
一般情况下，单目运算符最好重载为类的成员函数；双目运算符最好重载为类的友元函数；
以下双目运算符不能重载为类的友元函数：= | () | [] | ->
类型运算符只能以成员函数方式重载
流运算符只能以友元的方式重载
*/

class Complex
{
public:
    Complex();
    Complex(int real, int imag);
    ~Complex();
    Complex& Add(const Complex& other);
    Complex operator+(const Complex& other);
    //以友元函数重载，这里不能与以成员函数形式重载同时存在，所以注释
    //friend Complex operator+(const Complex& c1, const Complex& c2);
    /**
    这里需要注意，如果需要对第一个对象进行更新，那么第一个对象不能是const，这里的加法
    要返回一个新的对象 
    */
private:
    int real_;
    int imag_;
};

Complex::Complex(int real, int imag) : real_(real), imag_(imag)
{

}

Complex::Complex() : real_(0), imag_(0)
{
    
}

Complex& Complex::Add(const Complex& other)
{
    real_ += other.real_;
    imag_ += other.imag_;
    return *this;
}

Complex Complex::operator+(const Complex& other)
{
    int r = real_ + other.real_;
    int i = imag_ + other.imag_;
    Complex c1(r,i);
    return c1;
}

/*
Complex operator+(const Complex& c1, const Complex& c2)
{
    //friend function impl
}
*/

int main(int argc, char** argv) {

    return 0;
}