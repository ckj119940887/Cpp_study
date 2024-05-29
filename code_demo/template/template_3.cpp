#include <iostream>
#include <exception>
using namespace std;

// 非类型模板参数

template <typename T, int MAX_SIZE>
class Stack
{
public:
    Stack();
    ~Stack();
    void Push(const T& elem);
    void Pop();
    T& Top();
    const T& Top() const;
    bool Empty() const;
private:
    T* elems_;
    int top_;
};

template <typename T, int MAX_SIZE>
Stack<T, MAX_SIZE>::Stack() : top_(-1)
{
    elems_ = new T[MAX_SIZE];
}

template <typename T, int MAX_SIZE>
Stack<T, MAX_SIZE>::~Stack()
{
    delete[] elems_;
}

template <typename T, int MAX_SIZE>
void Stack<T, MAX_SIZE>::Push(const T& elem)
{
    if(top_ + 1 >= MAX_SIZE)
        throw out_of_range("Stack<>::Push() stack full");
    
    elems_[++top_] = elem;
}

template <typename T, int MAX_SIZE>
void Stack<T, MAX_SIZE>::Pop()
{
    if(top_ <= 0)
        throw out_of_range("Stack<>::Pop() stack empty");

    --top_;
}

template <typename T, int MAX_SIZE>
T& Stack<T, MAX_SIZE>::Top()
{
    if(top_ + 1 <= 0)
        throw out_of_range("Stack<>::Top() stack empty");

    return elems_[top_];
}

template <typename T, int MAX_SIZE>
const T& Stack<T, MAX_SIZE>::Top() const
{
    if(top_ + 1 <= 0)
        throw out_of_range("Stack<>::Top() stack empty");

    return elems_[top_];
}

template <typename T, int MAX_SIZE>
bool Stack<T, MAX_SIZE>::Empty() const
{
    return top_ == -1 ? true : false;
}

int main()
{
    //类模板只能显式实例化
    Stack<int, 100> s;
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