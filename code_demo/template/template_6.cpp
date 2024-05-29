#include <iostream>
using namespace std;

//成员模板
template <typename T>
class MyClass
{
private:
    //这里SubType是一个类型，而不是T的一个成员，因为已经用typename声明了
    typename T::SubType* ptr_;
public:
};

class Test
{
public:
    typedef int SubType;
};

int main()
{
    //传入的类型必须有子类型SubType
    MyClass<Test> t;

    return 0;
}