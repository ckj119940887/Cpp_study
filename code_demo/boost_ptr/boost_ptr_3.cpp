#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
using namespace std;

//weak_ptr解决循环引用的问题

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

    void Fun()
    {
        cout << "Fun ..." << endl;
    }
};

int main()
{
    boost::weak_ptr<X> p;
    {
        boost::shared_ptr<X> p2(new X);
        cout << p2.use_count() << endl;
        p = p2;
        cout << p2.use_count() << endl;

        boost::shared_ptr<X> p3 = p.lock();
        if(!p3)
            cout << "object is destroyed" << endl;
        else
            p3->Fun();
    }
    boost::shared_ptr<X> p4 = p.lock();
    if(!p4)
        cout << "object is destroyed" << endl;
    else 
        p4->Fun();

    return 0;
}