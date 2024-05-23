#include <iostream>
using namespace std;

/*
转换构造函数：带一个参数的构造函数，将一个类型转换为类类型。
即带一个参数的构造函数有两个功能：初始化和类型转换构造函数。
编译器隐式调用转换构造函数是危险的，可以直接重载运算符。或者使用explicit阻止隐式转换。
*/
class Test
{
public:
    Test();
    Test(int x);
    ~Test();
    void Display();
    Test& operator=(const Test& other);
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
    cout << "Destroy" << num_ << endl;
}

void Test::Display() {
    cout << num_ << endl;
}

Test& Test::operator=(const Test& other) {
    //如果other和this是同一个对象，则直接返回
    if(this == &other)
        return *this;
    this->num_ = other.num_;
    return *this;
}

int main() {
    Test t(20);
    t.Display();

    t = 10;     //1.调用转换构造函数将20这个整数转换成类类型(生成一个临时对象)
                //2.将临时对象赋值给t对象(调用的是=运算符)
    t.Display();

    Test t2 = 10; //这里的=不是运算符，表示初始化，等同于Test t(10)
    t2 = 20;      //这是赋值操作，而不是初始化。这里调用的是重载的=运算符。
    
    // explicit 关键字
    /*
    explicit Test(int x);
    Test t2 = 10; 将不会通过编译
    */

    return 0;
}