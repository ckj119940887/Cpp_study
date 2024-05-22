#ifndef __A_H
#define __A_H

/*
两个类需要相互引用而形成一个"环形"引用时，无法先定义使用。
此时需要使用前向声明，前向声明的类不能实例化,只能是指针或引用。
这里说的前向声明指的是的A和B的定义在两个头文件中，在class B的头文件中，
提前声明class A，比如 class A; 此时不知道A的具体定义是什么，所以无法
实例化对象，但是可以使用指针或引用。
*/

class A;

class B {
public:
    B(void);
    ~B(void);

    // A a_; 报错
    A *a_;
};

#endif