#include <iostream>
#include <memory>
#include <vector>
using namespace std;

/**
unique_ptr提供了一种独占所有权的智能指针(多个指针不能指向同一个对象)，允许动态分配的对象在其生命周期
结束时自动释放内存。
*/


class Person
{
public:
    Person()
    {
        cout << "construction function" << endl;
    }

    void Demo()
    {
        cout << "Person Demo" << endl;
    }

    ~Person()
    {
        cout << "destruction function" << endl;
    }
};

// unique_ptr创建方式
void test01()
{
    //管理单一动态对象
    unique_ptr<Person> up1(new Person);
    up1->Demo();

    //管理动态数组对象
    //注意这里一定是Person[]
    unique_ptr<Person[]> up2(new Person[2]);
    up2[0].Demo();
    up2[1].Demo();
}

void test02()
{
    unique_ptr<Person> up(new Person);

    // 返回unique_ptr管理的动态对象指针
    Person* person1 = up.get();

    // 释放up的动态对象指针所有权，返回其管理的动态指针
    // release之后，指针生命期结束后不会自动释放，需要我们手动释放，所以不要随便调用release
    Person* person2 = up.release();
    delete person2;

    // 释放并销毁 unique_ptr所管理的动态对象指针
    up.reset();
    // 释放并销毁 unique_ptr所管理的动态对象指针,并重新持有新创建的动态对象
    up.reset(new Person);

    //swap交换两个unique_ptr对象管理的动态对象
    unique_ptr<Person> sp(new Person);
    up.swap(sp);
}

/*
unique_ptr特性：
1.同时只能有一个unique_ptr对象来持有动态对象资源
2.unique_ptr对象不支持默认拷贝、默认赋值，即unique_ptr不能以值的方式用作函数参数以及存储到STL容器中
3.unique_ptr对象支持移动拷贝、移动赋值
*/
void test03()
{
    unique_ptr<Person> up1(new Person);    
    unique_ptr<Person> up2(new Person);    

    //move将up1从左值变成右值
    unique_ptr<Person> up3(move(up1));
    up2 = move(up3);
}

/*
unique_ptr自定义删除器:
unique_ptr可用于管理new出来的动态对象，也可以管理其他需要手动关闭的资源，如文件对象。
unique_ptr默认使用delete，delete[]来释放被管理的对象。当管理的对象不能用delete和delete[]来删除时，
就需要自定义删除器。
*/

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

void test04()
{
    //函数对象作为删除器
    unique_ptr<FILE, Deleter> up(fopen("./demo.txt", "w"), Deleter());
    //使用函数模板来声明
    unique_ptr<FILE, function<void(FILE *)>> up(fopen("./demo.txt", "w"), Deleter());

    //普通函数作为删除器
    //使用decltype动态推导出
    unique_ptr<FILE, decltype(&my_deleter)> up(fopen("./demo.txt", "w"), my_deleter);
    unique_ptr<FILE, void(*)(FILE*)> up(fopen("./demo.txt", "w"), my_deleter);
    unique_ptr<FILE, function<void(FILE*)>> up(fopen("./demo.txt", "w"), my_deleter);
}


int main()
{
    test02();

    return 0;
}