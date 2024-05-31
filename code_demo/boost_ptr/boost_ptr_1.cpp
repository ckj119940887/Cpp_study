#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
using namespace std;

/*
智能指针：
将堆对象的生存期用栈对象(智能指针就是栈对象)来管理，当new一个堆对象的时候，立刻用
智能指针来接管，具体做法是在构造函数进行初始化(用一个指针指向堆)，在析构函数中用
delete 来释放堆对象。

由于智能指针本身就是一个栈对象，它的作用域结束的时候，自动调用析构函数，从而调用了
delete释放了堆对象。
*/

/*
scoped_ptr<T>:当这个指针的作用域结束之后自动释放，与auto_ptr不同之处在于，
所有权不能转移，但是可以交换。

shared_ptr<T>:内部维护一个引用计数器来判断此指针是不是需要被释放。线程安全。

weak_ptr<T>:弱指针，不控制对象的生命期，但知道对象是否还活着。如果对象还活着，
可以提升为有效的shared_ptr；如果对象死了，提升会失败，返回一个空的shared_ptr。

scoped_array<T>:与scoped_ptr相似，用来处理数组

shared_array<T>:与shared_ptr相似，用来处理数组
*/

class X
{
public:
    X()
    {
        cout << "X ..." << endl;
    }
    ~X()
    {
        cout << "~X ..." << endl;
    }
};

int main()
{
    boost::scoped_ptr<X> p(new X);
    //会报错，scoped_ptr即不能被拷贝，也不能被赋值，即所有权不转移
    //boost::scoped_ptr<X> p2(p);

    boost::shared_ptr<X> s1(new X);
    cout << s1.use_count() << endl;
    boost::shared_ptr<X> s2 = s1;
    cout << s2.use_count() << endl;
    s1.reset();
    cout << s2.use_count() << endl;
    s2.reset();

    return 0;
}