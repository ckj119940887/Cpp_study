#include <iostream>
#include <string.h>
using namespace std;

/*
宏替换：不做类型检查
重载：为每个类型提供一个重载版本，程序自己来维护这些重载的版本
模板：为相同逻辑功能提供一个模板，将类型当作参数来传递，让编译器实例化对应版本的函数来处理。
*/

//函数模板
//将定义和实现放在一个头文件中
template <typename T>
const T& max(const T& a, const T& b)
{
    return a > b ? a : b;
}

//函数模板特化
template <>
const char* const& max(const char* const& a, const char* const& b)
{
    return strcmp(a,b) < 0 ? b : a;
}

//函数模板重载
template <typename T>
const T& max(const T& a, const T& b, const T& c)
{
    return ::max(a, b) < c ? c : ::max(a, b);
}

//非模板函数重载
const int& max(const int& a, const int& b)
{
    return a > b ? a : b;
}

class Test
{
public:
    friend bool operator >(const Test& t1, const Test& t2)
    {
        return true;
    }
};

int main()
{
    //这里直接使用max会报错，因为std中也有max的定义
    //max(5.5, 6.6);

    //表明是全局定义的函数
    ::max(5.5, 6.6);

    //必须重载>，采能正常运行，因为默认情况下Test没有明确>的含义
    Test t1;
    Test t2;
    ::max(t1, t2);

    //这里需要提供一个函数模板特化，否则比较的就是指针值的大小，而不是字符串值的大小
    const char* str1 = "aaa";
    const char* str2 = "zzz";
    cout << ::max(str1, str2) << endl;

    cout << ::max(1,2,3) << endl;

    //下面两行优先调用非模板函数重载
    cout << ::max('a', 100) << endl;
    cout << ::max(97, 100) << endl;

    //明确指明调用模板函数
    cout << ::max<>(97, 100) << endl;
    cout << ::max<int>(97, 100) << endl;
    cout << ::max<int>('a', 100) << endl;

    return 0;
}