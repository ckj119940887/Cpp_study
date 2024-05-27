#include <iostream>
using namespace std;

/*
采用虚继承来解决二义性。

class B1 : virtual public BB

为最远的派生类提供唯一的基类成员，而不重复多次拷贝
*/

/*
虚基类的成员是由最远派生类的构造函数通过调用虚基类的构造函数进行初始化的。
在整个继承结构中，直接或间接继承虚基类的所有派生类，都必须在构造函数的成员初始化表中
给出对虚基类的构造函数的调用。如果未列出，则表示调用该虚基类的默认构造函数。
在建立对象时，只有最派生类的构造函数调用虚基类的构造函数，该派生类的其他基类
对虚基类构造函数的调用被忽略。
*/

class Furniture
{
public:
    Furniture(int weight) : weight_(weight)
    {

    }
    int weight_;
};

class Bed : virtual public Furniture
{
public:
    Bed(int weight) : Furniture(weight)
    {

    }

    void Sleep()
    {
        cout << "Sleep ..." << endl;
    }
};

class Sofa : virtual public Furniture
{
public:
    Sofa(int weight) : Furniture(weight)
    {

    }

    void WatchTV()
    {
        cout << "Watch TV" << endl;
    }
};

class SofaBed : public Bed, public Sofa
{
public:
    SofaBed(int weight) : Bed(weight), Sofa(weight), Furniture(weight)
    {

    }

    void FoldOut()
    {
        cout << "FoldOut ... " << endl;
    }

    void FoldIn()
    {
        cout << "FoldIn ... " << endl;
    }
};

int main()
{
    SofaBed sofaBed(10);
    cout << sofaBed.weight_ << endl;

    return 0;
}