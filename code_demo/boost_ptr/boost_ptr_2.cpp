#include <iostream>
#include <boost/shared_ptr.hpp>
using namespace std;

class Parent;
class Child;

typedef boost::shared_ptr<Parent> parent_ptr;
typedef boost::shared_ptr<Child> child_ptr;

class Child
{
public:
    Child()
    {
        cout << "Child ..." << endl;
    }

    ~Child()
    {
        cout << "~Child ..." << endl;
    }

    parent_ptr parent_;
};

class Parent
{
public:
    Parent()
    {
        cout << "Parent ..." << endl;
    }
    
    ~Parent()
    {
        cout << "~Parent ..." << endl;
    }

    child_ptr child_;
    //解决方法2
    //boost::weak_ptr<Child> child_;
};

int main(void)
{
    parent_ptr parent(new Parent);
    child_ptr child(new Child);
    //这里就构成了循环引用,进而导致无法调用构造函数
    parent->child_ = child;
    child->parent_ = parent;

    //解决方法1：手动打破循环引用
    //parent->child_.reset();

    //解决方法2：weak_ptr
    /*
    强引用：只要有一个对象引用存在，对象就不能释放
    弱引用：并不增加对象的引用计数，但知道对象是否存在
    通过weak_ptr访问对象的成员时，需要提升为share_ptr，如果对象存在，提升成功；如果不存在，提升失败。
    */

    return 0;
}