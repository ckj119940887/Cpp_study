#include <iostream>
#include <vector>
#include <boost/weak_ptr.hpp>
using namespace std;

/*
智能指针的工厂函数时一个创建智能指针的函数，用于方便地创建特定类型的智能指针对象。
make_unique-->unique_ptr
make_shared-->shared_ptr

这些工厂函数保证是异常安全的，即使发生了异常，程序依然能够保持数据结构的一致性和资源的
正常释放。
*/

class Person
{
public:
    Person()
    {
        cout << "construction function" << endl;
    }

    Person(int, int)
    {
        cout << "construction function with parameters" << endl;
    }

    ~Person()
    {
        cout << "destruction function" << endl;
    }
};

void test01()
{
    unique_ptr<Person> up1 = make_unique<Person>();
    unique_ptr<Person> up2 = make_unique<Person>(19,12);
    // 创建动态数组类型的时候默认调用的是无参构造函数，所以必须有无参构造函数
    unique_ptr<Person[]> up3 = make_unique<Person[]>(3);
}

void do_logic(unique_ptr<Person> uq, int number)
{
}

int get_number()
{
    cout << "get number" << endl;
    throw exception();
    return 100;
}

void test02()
{
    try
    {
        //异常不安全，无法调用析构函数
        do_logic(unique_ptr<Person>(new Person), get_number());

        //异常安全，可以调用析构函数
        do_logic(make_unique<Person>(), get_number());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void test03()
{
    //make_shared函数并不支持创建用于管理动态对象数组的shared_ptr对象
    shared_ptr<Person> sp = make_shared<Person>(10, 20);
}

int main()
{

    return 0;
}