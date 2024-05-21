#include <iostream>
using namespace std;

// 使用 extern "C"表明当前函数是C函数，而不是可以重载的函数
/*
//实现C和C++混合编程
#ifdef _cplusplus
extern "C"
{
#endif
    void func(int a);
    void fucn1(int a);
#ifdef _cplusplus
}
#endif
*/

/*
// 带参数默认值的函数，赋予默认值的参数必须从右向左，即从最右便开始
// 才可以赋予默认值，中间不能有空着不赋值的情况。赋予默认值可能造成
// 二义性。
int func(int a = 1, int b = 1, int c = 1);
int func(int a = 1, int b = 1);

此时在调用 func(1,1); 的时候会报错，不知道匹配哪个函数。
*/

int temp = 100;

int main() {

    int temp = 50;
    // access the local variable 
    cout << temp << endl;
    // access the global variable
    cout << :: temp << endl;

    int *p = new int;
    *p = 10;
    cout << sizeof(*p) << endl;

    int *p1 = new int[10];
    cout << sizeof(*p1) << endl;

    delete p;
    delete [] p1;

    return 0;
}