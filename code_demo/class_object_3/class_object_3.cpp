#include <iostream>
#include "A.h"
#include "B.h"
using namespace std;

/*
外围类需要使用嵌套类对象作为底层实现，并且该嵌套类只用于外围类的
实现，且同时可以对用户隐藏该底层实现。
嵌套类没有对外围类成员的访问权限。
外围类没有对嵌套类私有成员的访问权限。
*/

class Outer {
public:
    class Inner {
    public:
        void Func();
    };

public:
    Inner obj_;
    void Func() {
        cout << "Outer" << endl;
        obj_.Func();
    }
};

void Outer::Inner::Func() {
    cout << "Inner" << endl;
}

int main(int argc, char ** args) {
    Outer o;
    o.Func();

    Outer::Inner i;
    i.Func();

    return 0;
}