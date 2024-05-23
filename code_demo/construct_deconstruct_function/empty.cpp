#include<iostream>
using namespace std;

/*
空类默认产生的成员
class Empty {};

Empty();//默认构造函数
Empty(const Empty&);//默认拷贝构造函数
~Empty();//默认析构函数
Empty& operator=(const Empty&);//默认赋值元算符
Empty* operator&();//取址运算符
cosnt Empty* operator&() const;//取址运算符const
*/

class Empty
{
public:
    Empty* operator&()
    {
        cout << "no const" << endl;
        return this;
    }
    const Empty* operator&() const
    {
        cout << "const" << endl;
        return this;
    }
};

int main(int argc, char** argv) {
    Empty e;
    Empty* t = &e; //调用的是不带const的取址运算

    const Empty i;
    const Empty* x = &i;

    return 0;
}