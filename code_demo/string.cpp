#include <iostream>
#include <string>
using namespace std;

/*
string支持长度可变的字符串
typedef basic_string<char> string;
typedef basic_string<wchar_t> wstring;
必须包含相应头文件 #include <string>
*/

/*
字符串对象的定义和初始化
string s1; //默认构造函数，空串
string s2(s1); //将s2初始化为s1的副本
string s3("value"); //初始化为字面值副本
string s4(n, 'c'); //初始化为字符'c'的n个副本
其他的构造函数详见 basic_string文档
*/

int main()
{
    string s1("abcd");
    cout << s1.size() << endl;
    cout << s1.length() << endl;
    cout << s1.empty() << endl;
    cout << s1.substr(1,3) << endl;

    return 0;
}