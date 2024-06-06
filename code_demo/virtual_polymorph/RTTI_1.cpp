#include <iostream>
using namespace std;

/*
RTTI:Run Time Type Identification,在运行时确定数据类型，这里主要指的是typeid和dynamic_cast.
typdeid即可以在编译期也可以在运行期获得类型信息
*/

class Box {};

class Animal {
public:
    virtual ~Animal() = default;
};

class Bee : public Animal {};
class Dog : public Animal {};

void compile_time()
{
    int a = 10;
    cout << typeid(a).name() << endl;

    //自定义对象类型
    Box box;
    cout << typeid(box).name() << endl;

    int* p = &a;
    cout << typeid(p).name() << endl;

    Box* pBox = new Box;
    cout << typeid(pBox).name() << endl;
}

void run_time()
{
    //这里牵扯到多态了，动态绑定，所以需要在运行时来确定类型
    Animal* animal = new Bee;
    cout << typeid(*animal).name() << endl;

    animal = new Dog;
    cout << typeid(*animal).name() << endl;
}

int main()
{
    compile_time();

    run_time();

    return 0;
}