#include <iostream>
#include <vector>
using namespace std;

/*
auto_ptr是c++98中引入的智能指针，用于自动管理动态分配的对象的生命周期。
在c++11中被废弃，c++17中被移除，存在严重的安全问题。

缺陷：
1.没有共享所有权：多个指针不能指向同一个对象
2.不支持拷贝语义：在拷贝或者赋值时，仅是进行资源的所有权转移，即无法放在容器中
*/

class Person
{
public:
    Person()
    {
        cout << "construction function" << endl;
    }

    ~Person()
    {
        cout << "destruction function" << endl;
    }
};

int main()
{
    //当ptr的生命周期结束时，会自动释放该对象
    //auto_ptr是不适合管理动态数组的
    //auto_ptr<Person> ptr(new Person);

    return 0;
}