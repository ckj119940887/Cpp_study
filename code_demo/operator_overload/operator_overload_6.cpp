#include <iostream>
using namespace std;

class Test
{
public:
    Test(int n) : n_(n)
    {
        cout << "Test(int n) : n_(n)" << endl;
    }
    Test(const Test& other)
    {
        cout << "Test(const Test& other)" << endl;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }

    //new operator不能被重载
    //operator new 可以被重载
    void* operator new(size_t size)
    {
        cout << "void* operator new(size_t size)" << endl;
        void* p = malloc(size);
        return p;
    }
    void operator delete(void* p)
    {
        cout << "void* operator delete(void* p)" << endl;
        free(p);
    }
    void operator delete(void* p, size_t size)
    {
        cout << "void* operator delete(void* p, size_t size)" << endl;
        free(p);
    }

    void* operator new(size_t size, void* p)
    {
        return p;
    }
    void operator delete(void*, void*)
    {
    }

    int n_;
};

//全局new 与 delete
void* operator new(size_t size)
{
    cout << "global void* operator new(size_t size)" << endl;
    void* p = malloc(size);
    return p;
}

void operator delete(void* p)
{
    cout << "global void operator delete(size_t size)" << endl;
    free(p);
}

void* operator new[](size_t size)
{
    cout << "global void* operator new[](size_t size)" << endl;
    void* p = malloc(size);
    return p;
}

void operator delete[](void* p)
{
    cout << "global void operator delete[](size_t size)" << endl;
    free(p);
}

int main(int argc, char** argv)
{
    Test *p1 = new Test(100); //new operator = operator new + 构造函数的使用
    delete p1;

    char chunk[10];
    Test *p2 = new (chunk) Test(200); //placement new，在已分配的内存上进行new + 构造函数的使用
    cout << p2->n_ << endl;
    p2->~Test(); //显式调用析构函数

    Test *p3 = (Test*)chunk;
    cout << p3->n_ << endl;

    //调用全局new和delete
    char* str1 = new char;
    delete str1;

    //调用全局new[]和delete[]
    char* str2 = new char[100];
    delete[] str2;

    return 0;
}