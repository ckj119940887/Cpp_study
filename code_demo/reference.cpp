#include <iostream>
using namespace std;

// 引用只是变量的别名，并没有分配空间，与对应变量共享空间。
// 引用在定义的时候要初始化。
// 引用一经初始化，不能重新指向其他变量。

// 引用作为参数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int test[] = {1,2,3,4,5};
// 引用作为返回值传递时的函数可以作为左值
// 不能返回局部变量的引用，因为在返回时局部变量已经被销毁
int& index(int i) {
    return test[i];
}

int main() {

    int temp = 100;
    int &a = temp;
    a = 10;
    cout << temp << endl;

    // const 引用是指向const 对象的引用
    const int val = 2024;
    const int &b = val;
    cout << b << endl;

    // const 引用可以指向非const对象，但是不能修改
    int val2 = 2034;
    const int& c = val2;

    int x = 5, y = 6;
    swap(x,y);
    cout << x << y << endl;

    index(0) = 11;
    cout << test[0] << endl;

    return 0;
}