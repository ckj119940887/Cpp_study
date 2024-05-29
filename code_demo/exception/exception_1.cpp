#include <iostream>
using namespace std;

double Divide(double a, double b)
{
    if(b == 0.0)
        throw 1;
    else 
        return a / b;
}

int main()
{
    //try中存放可能会产生异常的代码
    //throw可以在被调用函数中存放，也可以在try中存放
    try
    {
        cout << "division ..." << endl;
        cout << Divide(5.0, 0.0) << endl; 
    }
    catch(int) //可以捕获多种类型的异常
    {
        cout << "dividing by zero" << endl;
    }
    //catch(...) //可以捕获任意类型的异常
    
    return 0;
}