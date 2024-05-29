#include <iostream>
#include <string>
using namespace std;

//自定义异常类型
class MyException
{
public:
    MyException(const char* message)
        : message_(message) 
    {
        cout << "MyException ..." << endl;
    }

    MyException(const MyException& other) : message_(other.message_)
    {
        cout << "Copy MyException ..." << endl;
    }

    ~MyException()
    {
        cout << "~MyException ..." << endl;
    }

    string what() 
    {
        return message_;
    }

private:
    string message_;
};

double Divide(double a, double b)
{
    if(b == 0.0)
    {
        MyException e("division by zero");
        throw e; //此时会调用拷贝构造函数
    }
    else 
        return a / b;
}

int main()
{
    try
    {
        cout << "division ..." << endl;
        cout << Divide(5.0, 0.0) << endl; 
    }
    catch(MyException& e) 
    {
        cout << e.what() << endl;
    }
    
    return 0;
}