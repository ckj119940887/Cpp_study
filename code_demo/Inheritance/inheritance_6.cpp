#include <iostream>
using namespace std;

/**
多继承：
class 类名: 继承方式 基类1, 继承方式 基类2
可能会有大量的二义性

多继承中解决访问歧义的方法：
基类名::数据成员名(或成员函数)
*/

class Bed
{
public:
    Bed(int weight) : weight_(weight)
    {

    }

    void Sleep()
    {
        cout << "Sleep ..." << endl;
    }

    int weight_;
};

class Sofa
{
public:
    Sofa(int weight) : weight_(weight)
    {

    }

    void WatchTV()
    {
        cout << "Watch TV" << endl;
    }

    int weight_;
};

class SofaBed : public Bed, public Sofa
{
public:
    SofaBed() : Bed(0), Sofa(0)
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
    SofaBed sofaBed;
    //此时有二义性，所以需要明确指明
    sofaBed.Bed::weight_ = 100;
    sofaBed.Sofa::weight_ = 100;

    return 0;
}