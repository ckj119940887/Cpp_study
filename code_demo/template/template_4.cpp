#include <iostream>
#include <deque>
#include <exception>
using namespace std;

//缺省模板类参数
//deque<T>后面必须有空格
template <typename T, typename CONT = deque<T> >
class Stack
{
public:
    Stack()
    {

    }

    ~Stack()
    {

    }

    void Push(const T& elem)
    {
        elems_.push_back(elem);
    }

    void Pop()
    {
        elems_.pop_back();
    }

    T& Top()
    {
        return  elems_.back();
    }

    const T& Top() const
    {
        return  elems_.back();
    }

    bool Empty() const
    {
        return elems_.empty();
    }
private:
    CONT elems_;
    int top_;
};

int main()
{
    //类模板只能显式实例化
    Stack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);

    while(!s.Empty())
    {
        cout << s.Top() << endl;
        s.Pop();
    }

    return 0;
}