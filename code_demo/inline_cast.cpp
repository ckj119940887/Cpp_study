#include <iostream>
using namespace std;

// inline函数，编译器会直接进行替换和展开
// 对于频繁使用且短小的函数直接使用内联函数
inline int max(int a, int b) {
    return a > b ? a : b;
}

// 类型转换
/*
旧式转型：
(T)expr
T(expr)

新式转型：
const_cast<T>(expr):移除对象的常量性，这里的对象指的是指针或者引用。
                    使用const_cast不是为了修改常量对象的内容，是为了函数能够接受这个参数。
static_cast<T>(expr):隐式转换，完成算术类型的强制转换，可以将void*指针转换为任一类型的指针。
                     可以将基类指针转换成派生类指针。
reinterpret_cast<T>(expr):将数据以二进制形式重新解释。
dynamic_cast<T>(expr) : 执行安全向下转型操作，支持运行时识别指针或所指向的对象。
                        唯一一个无法用旧式转型替换的。
*/

void func(int& x) {
    cout << x << endl;
}

int main() {

    // 下面语法是错误的，只能针对指针和引用
    /*
    const int val = 100;
    int n = const_cast<int>(val);
    */

    const int val = 100;
    int* p = const_cast<int*>(&val); 
    *p = 200;
    // val还是100，并没有被修改。
    cout << val << endl;

    const int val2 = 200;
    int &t = const_cast<int&>(val2);
    t = 99;
    // val2还是200，并没有被修改。
    cout << val2 << endl;

    func(const_cast<int&>(val2));

    int n = static_cast<int>(3.14);
    cout << n << endl;

    void *p2 = &n;
    int* p3 = static_cast<int*>(p2);

    // 转换结束后，i与p的值是完全相同的。
    int i;
    char *p = "hello world!\n";
    i = reinterpret_cast<int>(p);

    // pc所指向的对象是int型，并非字符串，所以不能当作字符指针进行操作
    // strlen(pc) 会报错。
    int *ip;
    char *pc = reinterpret_cast<char*>(ip);

    return 0;
}