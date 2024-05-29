#include <iostream>
using namespace std;

//自定义异常类型
//析构函数应该尽量不要抛出异常
//构造函数中可以抛出异常，对于已构造的要销毁，对于未构造完成不用管，对于已构造的变量会自动销毁，但是指针类型成员则需要特殊处理。
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

int main()
{
    //try-catch可以嵌套，如果内层无法处理，将被传到外层进行处理
    //如果内层捕获了，不会再向外传播
    try
    {
        try
        {
            throw MyException("test exception");
        }
        catch(int)
        {
            cout << "catch a int exception" << endl;
        }
        
    }
    catch(MyException& e) 
    {
        cout << "catch MyException" << endl;
    }
    
    return 0;
}