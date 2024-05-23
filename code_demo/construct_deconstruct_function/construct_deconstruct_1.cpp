#include <iostream>
using namespace std;

// 构造函数不能有返回类型，不带参数的构造函数为默认构造函数。
// 构造函数在通常情况下被声明为公有函数，否则不能像其他成员函数那样被
// 显式调用。当构造函数被声明为private时往往有特殊目的。
// 如果自己提供了构造函数，那么编译器将不再提供函数体为空的默认构造函数
// 此时，可能出错，所以应该自己提供默认构造函数。

/*
析构函数没有参数，不能被重载。
*/

class Test
{
public:
    Test();
    Test(int x);
    ~Test();
private:
    int num_;
};

Test::Test() {
    num_ = 0;
    cout << "initialization" << endl;
}

Test::Test(int x) {
    num_ = x;
}

Test::~Test() {

}

// 全局对象先于main函数
Test x;

int main() {
    Test p;

    Test* t = new Test[2]{1, 2};
    delete[] t;
}