#include <iostream>
using namespace std;

class Test
{
public:
    Test();
    Test(int x);
    ~Test();
private:
    int num_;
};

class Container {
public:
    // 对于所有对象来说TYPE_A和TYPE_B都是常量。
    enum E_TYPE {
        TYPE_A = 100,
        TYPE_B = 200
    };
public:
    Container() : kNum_(0), test_(c)
    {
        cout << "Container ... " << endl;
    }
    Container(int x) : kNum_(x), test_(c)
    {
        cout << "Container ... " << endl;
    }
    ~Container()
    {
        cout << "~Container ... " << endl;
    }
    void DisplayKNum() {
        cout << kNum_ << endl;
    }
private:
    Test t_;
    int c;
    //常量的初始化只能在构造函数初始化列表中完成初始化
    const int kNum_;
    //引用的初始化只能在构造函数初始化列表中完成初始化
    int& test_;
    //对象成员(对象对应的类没有默认构造函数)的初始化只能在构造函数初始化列表中完成初始化
};

Test::Test() {
    num_ = 0;
    cout << "initialization" << endl;
}

// 直接在构造函数初始化列表中初始化
Test::Test(int x) : num_(x)
{
}

Test::~Test() {
    cout << "Destroy" << num_ << endl;
}

int main() {
    //对于如下两个对象，kNum_仅对于对象自己是常量
    //如果希望对于所有对象都是常量，则需要用到enum
    Container c1(10);
    Container c2(20);
    c1.DisplayKNum();
    c2.DisplayKNum();

    cout << c1.TYPE_A << endl;
    cout << c2.TYPE_A << endl;

    return 0;
}