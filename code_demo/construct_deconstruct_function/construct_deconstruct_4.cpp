#include <iostream>
using namespace std;

/*
拷贝构造函数: 使用一个已经存在的对象来初始化一个新的用一类型的对象。
声明： 只有一个参数并且参数为该类对象的引用
如果类中没有明确声明，则自动生成一个缺省赋值构造函数，作为该类的共有成员。
*/

class Test
{
public:
    Test();
    Test(int x);
    // 拷贝构造函数,这里如果不用引用就会声明一个新的对象，Test x
    Test(const Test& x);
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

Test::Test(const Test& x) : num_(x.num_)
{

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

Test testFunc(const Test& x) {
    // 在返回时，需要调用拷贝构造函数来建立一个临时对象，将x拷贝给临时对象
    return x;
}

// 这里不能写Test&，而应该是const Test&，因为参数就是该类型的
const Test& testFunc2(const Test& x) {
    // 不会调用拷贝构造函数，会直接返回x，因为这里是引用
    return x;
}

// 如果实在是要使用Test&，则应该使用const_cast
Test& testFunc3(const Test& x) {
    return const_cast<Test&>(x);
}

int main() {

    Test t1(10);
    Test t2(t1);
    t2.Display();

    testFunc(t1); // 析够函数会多打印一次，释放临时变量

    return 0;
}