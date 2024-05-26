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

int main(int argc, char** argv) {
    Integer i(100);
    i.Display();

    Integer n2 = ++i;
    n2.Display();

    Integer n3 = i++;
    n3.Display();
    i.Display();

    return 0;
}