#include <iostream>
using namespace std;

/*
const 与 define的区别：
1. const定义的常量有类型，define只是简单替换
2. const定义的变量在编译时分配内存，define只是替换操作，不分配内存
3. 作用域不同，define从定义的位置开始，const遵循变量的作用域
尽量用const、enum替换define
*/

// 常量，必须初始化
// const 数据类型 常量名 = 值
// 数据类型 const 常量名 = 值
int main(int argc, char ** args) {
    const int a = 100;
    int b = 10;

    // 指向常量的指针，const在*左边，表示*p为常量，*p不能更改指针指向的内容
    const int *p = &a;
    // p = &b;
    // *p = 100; 报错，所指向的数据是常量

    // const在*右边，指针为常量，必须初始化
    int * const p2 = &b;
    // p2 = &a; 报错，不能重新指向新的变量
    *p2 = 200;  // p2所指向的数据并不是常量，可以修改
    cout << b << endl;

    /*
    // 下面代码仍会报错，无法将const int * 赋值给 int * const
    const int c = 10;
    int * const p3 = &c;
    *p3 = 5;
    */

    /*
    // 下面代码仍会报错，无法将const int * 赋值给 int* const*
    const int c = 10;
    int * const *p4 = &c;
    */

    // const int * const p = &n; //*p3是常量，p3也是常量

    return 0;
}