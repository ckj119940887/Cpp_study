#include <iostream>
using namespace std;

// dynamic_cast能够检验具有继承关系的父子类型的指针、引用的转换是否时安全。
// dynamic_cast也分为编译期类型转换，运行时类型转换。
// 子类的大小一定大于等于父类大小，所以父类可以指向子类。

class Animal {};
class Dog : public Animal {};

int main()
{
    Dog* dog = new Dog;
    //子类指针转换为父类指针，安全类型转换
    Animal* animal = dynamic_cast<Animal*>(dog);
    cout << animal << endl;

    return 0;
}