#include <iostream>
#include <string.h>
using namespace std;

/*
空类默认产生的成员
class Empty {};

Empty();//默认构造函数
Empty(const Empty&);//默认拷贝构造函数
~Empty();//默认析构函数
Empty& operator=(const Empty&);//默认赋值元算符
Empty* operator&();//取址运算符
cosnt Empty* operator&() const;//取址运算符const
*/

class String
{
public:
    String(char* str);
    String(const String& other);
    ~String();
    void Display();
    String& operator=(const String& other);
private:
    /*
    对于禁止拷贝的成员的，其拷贝函数也需要实现，具体实现方式为：
    将构造函数的声明至于private下，同时不给出具体实现。 
    String(char* str);
    String(const String& other);
    ~String();
    String& operator=(const String& other);
    */
    char* AllocAndCopy(char* str);
    char* str_;
};

String::String(char* str)
{
    str_ = AllocAndCopy(str);
}

String::String(const String& other)
{
    str_ = AllocAndCopy(other.str_);
}

String::~String() 
{
    delete [] str_;
}

void String::Display() {
    cout << str_ << endl;
}

char* String::AllocAndCopy(char* str) {
    int len = strlen(str) + 1;
    char* temp = new char[len]; 
    memset(temp, 0, len);
    strcpy(temp, str);
    return temp;
}

String& String::operator=(const String& other)
{
    if(this == &other)
        return *this;

    delete [] str_;
    this->str_ = AllocAndCopy(other.str_);

    return *this;
}

int main() {
    String s1("AAA");
    s1.Display();

    /*
    这里会报错。
    调用默认的拷贝构造函数，即浅拷贝构造函数，s2.str_ = s1.str_;
    这里的问题是，仅仅进行了指针的赋值操作，在最后调用析构函数时，会调用两次，但是针对的是同一个内存空间。
    解决方案是构造深拷贝构造函数。
    */
    //String s2 = s1; 

    String s3 = s1;
    s3.Display();

    /*
    String s4;
    s4.Display();
    s4 = s1;
    同理，与上面相似，需要重载=运算符
    */

    return 0;
}