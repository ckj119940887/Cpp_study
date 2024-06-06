#include <iostream>
#include <vector>
#include <boost/weak_ptr.hpp>
using namespace std;

/*
weak_ptr:用于解决shared_ptr引发的循环引用问题(A引用B，B引用A)，不单独使用。
可以观测shared_ptr管理的对象，但不会增加引用计数。即weak_ptr不拥有所指向对象的所有权。
shared_ptr被销毁后，weak_ptr会自动失效。
*/

class Person
{
public:
    Person()
    {
        cout << "construction function" << endl;
    }

    void Show()
    {
        cout << "Show" << endl;
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
    //weak_ptr是shared_ptr的辅助，其自身并不拥有资源所有权
    shared_ptr<Person> sp1 = make_shared<Person>(10,30);

    //允许对象拷贝，对象赋值，导致对同一对象的持有数增加
    weak_ptr<Person> wp1(sp1);

    weak_ptr<Person> wp2;
    wp2 = sp1;

    //weak_ptr使用时，不能直接访问对象成员
    //必须使用lock方法返回一个shared_ptr对象(会增加引用)
    if(wp1.expired())
        return;
    auto sp2 = wp1.lock();
    sp2->Show();
}

class LinkNode
{
public:
    int data;
    shared_ptr<LinkNode> prev;
    shared_ptr<LinkNode> next;
    //将共享引用改成弱引用
    /*
    weak_ptr<LinkNode> prev;
    weak_ptr<LinkNode> next; 
    */

    LinkNode(int value)
    {
        data = value;
        cout << "Construction Function" << endl;
    }

    ~LinkNode()
    {
        cout << "Destruction Function" << endl;
    }

};

void test02()
{
    shared_ptr<LinkNode> node1(new LinkNode(10));
    shared_ptr<LinkNode> node2(new LinkNode(20));

    //出现循环引用
    //只有prev和next被销毁，LinkNode才会被释放
    //只有两个LinkNode被释放，prev和next才会被释放
    node1->next = node2;
    node2->prev = node1;
}

int main()
{

    return 0;
}