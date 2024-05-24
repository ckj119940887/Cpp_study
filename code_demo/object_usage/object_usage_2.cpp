#include <iostream>
using namespace std;

/*
C语言中的extern和static
不要子头文件中定义全局变量，尽量在.c中定义，比如在A.c中定义 int n = 0;
然后可以在B.c中使用extern引用，比如extern int n;
如果在头文件中定义了int n = 0; 然后B.c和D.c再引用头文件，造成的结果就是
在两个c文件中重新声明了两个变量。

或者直接定义一个static int n = 0;

C++支持上述两种用法。
*/

class Date
{
public:
    Date(int year) : year_(year)
    {

    }

    // 使用静态函数来判断则可以不用申请对象并分配空间
    // 如果没有静态函数，就必须先申请一个对象，然后才能调用IsLeapYear()
    static bool IsLeapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    bool IsLeapYear() {
        return ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0));
    }
private:
    int year_;
};

int main(int argc, char** argv) {
    Date d(2011);
    cout << d.IsLeapYear() << endl;

    cout << Date::IsLeapYear(2022) << endl;

    return 0;
}