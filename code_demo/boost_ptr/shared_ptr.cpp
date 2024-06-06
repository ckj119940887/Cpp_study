#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
using namespace std;

/*
shared_ptr允许多个实例共享对同一对象的所有权。
shared_ptr使用引用计数来跟踪有多少个shared_ptr实例指向同一个对象，并在最后一个案例销毁时释放对象。
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

//shared_ptr的创建
void test01()
{
    shared_ptr<Person> sp1(new Person);
    //动态数组对象
    shared_ptr<Person[]> sp1(new Person[10]);
}

//shared_ptr操作函数
void test02()
{
    shared_ptr<Person> sp1(new Person(10,20));
    shared_ptr<Person> sp2(new Person(100,300));

    Person* person = sp1.get();

    sp1.swap(sp2);

    sp1.reset();
    sp1.reset(new Person(1,2));
}

/*
shared_ptr特性：
1.多个shared_ptr对象能够同时持有并管理同一个动态对象
2.当shared_ptr发生对象拷贝、赋值时都会导致多个shared_ptr对象持有同一个动态对象。
*/
void test03()
{
    shared_ptr<Person> sp1(new Person);
    //允许对象拷贝，对象赋值，导致对同一对象的持有数增加
    shared_ptr<Person> sp2(sp1);
    shared_ptr<Person> sp3;
    sp3 = sp1;

    //允许对象移动拷贝、移动赋值
    // sp3对应的资源转移到sp4上，sp3就没有了
    shared_ptr<Person> sp4 = move(sp3);

    shared_ptr<Person> sp5;
    sp5 = move(sp1);

    //允许存储到容器中
    vector<shared_ptr<Person>> vec;
    vec.push_back(sp2);
    vec.push_back(sp4);
    vec.push_back(sp5);
}

void test04()
{
    shared_ptr<Person> sp1(new Person);
    cout << sp1.use_count() << endl;

    shared_ptr<Person> sp2(sp1);
    cout << sp2.use_count() << endl;

    shared_ptr<Person> sp3;
    sp3 = sp1;
    cout << sp3.use_count() << endl;

    //判断是否独占资源
    cout << sp3.unique() << endl;

    //释放资源
    sp2.reset();
    cout << sp2.use_count() << endl;

}

struct Deleter
{
    void operator()(FILE* fp)
    {
        cout << "file is closed" << endl;
        if(fp != nullptr)
        {
            fclose(fp);
            fp = nullptr;
        }
    }
};

void my_deleter(FILE* fp)
{
    cout << "file is closed" << endl;

    if(fp != nullptr)
    {
        fclose(fp);
        fp = nullptr;
    }
}

//自定义删除器，与unique_ptr不太一样
void test05()
{
    shared_ptr<FILE> sp1(fopen("./demo.txt", "w"), my_deleter);
    shared_ptr<FILE> sp1(fopen("./demo.txt", "w"), Deleter());
}

int main()
{

    return 0;
}