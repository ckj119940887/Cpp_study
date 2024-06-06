#include <iostream>
using namespace std;

class Animal {
public: 
    virtual ~Animal();
};

class Dog : public Animal {};

int main()
{
    Animal* animal = nullptr;
    Dog* dog = nullptr;

    //这里转换失败，将小对象的指针转换成大对象的指针。
    animal = new Animal;
    dog = dynamic_cast<Dog*>(animal);

    //这里转换成功。
    animal = new Dog;
    dog = dynamic_cast<Dog*>(animal);

    return 0;
}