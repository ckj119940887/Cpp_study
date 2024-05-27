#include <iostream>
using namespace std;

/*
派生类对象也是基类对象，这意味着使用基类的地方也可以使用派生类来替换。

当派生类以public方式继承基类时，编译器自动执行转换(向上转型upcasting安全转换):
派生类对象指针自动转化为基类对象指针
派生类对象引用自动转化为基类对象引用
派生类对象自动转化为基类对象

当派生类以private/protected方式继承基类时:
派生类对象指针(引用)转化为基类对象指针(引用)需用强制类型转化。但不能用static_cast,
要用reinterpret_cast。
不能把派生类对象强制转换为基类对象。
*/

/*
static_cast: 用于编译器认可的静态转换。比如说从char到int，从double到int。或者具有转换构造函数，或者重载类型转换运算符。
reinterpret_cast: 用于编译器不认可的静态转换。从int*到int。
const_cast: 去除常量。
dynamic_cast: 用于动态转换，安全的向下转换，从基类到派生类。
*/

/*
基类到派生类的转换：(尽量不要做这种转换)
基类对象指针(引用)可用强制类型转换为派生类对象指针(引用)，而基类对象无法执行这类转换。
向下转型不安全，没有自动转换机制
*/

class Employee
{
public:
    Employee(const string& name, const int age, const int deptno) : name_(name),
        age_(age), deptno_(deptno)
    {

    }
private:
    string name_;
    int age_;
    int deptno_;
};

class Manager : public Employee
{
public:
    Manager(const string& name, const int age, const int deptno, const int level) : 
        Employee(name, age, deptno), level_(level) 
    {

    }
private:
    int level_;
};

class Manager2 : private Employee
{
public:
    Manager2(const string& name, const int age, const int deptno, const int level) : 
        Employee(name, age, deptno), level_(level) 
    {

    }
private:
    int level_;
};

int main()
{
    Employee e1("kejun", 25, 20);
    Manager m1("chen", 33, 30, 10);

    Employee* pe = &e1; 
    Manager* pm = &m1; 

    pe = &m1; //派生类指针可以转化为基类指针，派生类对象可以看作基类对象
    e1 = m1; //派生类对象转换成基类对象，派生类中新增的成员和变量可能就消失了
    //pm = &e1; // 相反则是不对的

    Manager2 m2("dog", 33, 364, 10);
    Manager2* pm2;
    pm2 = &m2;

    //pe = &m2; //无法直接转换
    pe = reinterpret_cast<Employee*>(pm2);

    //无法自动完成从基类指针到派生类指针的转换，但是是不安全的
    pm = static_cast<Manager*>(pe);
    pm = reinterpret_cast<Manager*>(pe);

    return 0;
}