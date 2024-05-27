#include <iostream>
using namespace std;

class Furniture
{
public:
    Furniture(int weight) : weight_(weight)
    {

    }
    int weight_;
};

class Bed : public Furniture
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

class Sofa : public Furniture
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
    SofaBed(int weight) : Bed(weight), Sofa(weight)
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
    //此时仍有二义性
    cout << sofaBed.Bed::weight_ << endl;
    cout << sofaBed.Sofa::weight_ << endl;

    return 0;
}