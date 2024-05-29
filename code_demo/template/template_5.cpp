#include <iostream>
using namespace std;

//成员模板
template <typename T>
class MyClass
{
private:
    T value;
public:
    /*
    void Assign(const MyClass<T>& x)
    {
        value = x.value;
    }
    */
    template <class X>
    void Assign(const MyClass<X>& x)
    {
        //这里x不能直接访问value，因为X可能与T类型不一样，所以需要通过成员函数
        value  = x.GetValue();
    }
    T GetValue() const 
    {
        return value;
    }
};

int main()
{
    MyClass<double> d;
    MyClass<int> i;

    d.Assign(d);
    //报错，类型不一样,需要把成员函数定义成模板
    d.Assign(i);

    return 0;
}