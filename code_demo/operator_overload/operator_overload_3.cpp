#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    String(const char* str="");
    String(const String& ohter);
    ~String(void);
    char* AllocAndCpy(const char* str);
    String& operator=(const String& other);
    String& operator=(const char* other);
    bool operator!() const;
    char& operator[](unsigned int n);
    const char& operator[](unsigned int n) const;
    String& operator+=(const String& other);
    void Display();

    friend ostream& operator<<(ostream& os, const String& output);
    friend istream& operator>>(istream& is, String& input);

    friend String operator+(const String& s1, const String& s2);

private:
    String& Assign(const char* other);
    char* str_;
};

String::String(const char* str) {
    str_ = AllocAndCpy(str);
}

String::String(const String& other)
{
    str_ = AllocAndCpy(other.str_);
}

String::~String()
{
    delete [] str_;
}

char* String::AllocAndCpy(const char* str)
{
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
    return Assign(other.str_);
}

String& String::operator=(const char* str)
{
    return Assign(str);
}

String& String::Assign(const char* str)
{
    delete [] str_;
    str_ = AllocAndCpy(str);
    return *this;
}

bool String::operator!() const
{
    return strlen(str_) != 0;
}

char& String::operator[](unsigned int n)
{
    //这里两个函数的内容是相同的，为了减少重复
    //我们需要让non-const版本调用const 版本
    //return str_[n];
    return const_cast<char&>(static_cast<const String&>(*this)[n]); 
}

const char& String::operator[](unsigned int n) const
{
    return str_[n];
}

ostream& operator<<(ostream& os, const String& output)
{
    os << output.str_;
    return os;
}

istream& operator>>(istream& is, String& input)
{
    char temp[1024];
    cin >> temp;
    input = temp;
    return is;
}

String operator+(const String& s1, const String& s2)
{
    int len = strlen(s1.str_) + strlen(s2.str_) + 1;
    char* newstr = new char[len];
    memset(newstr, 0, len);
    strcpy(newstr, s1.str_);
    strcat(newstr, s2.str_);
    String s(newstr);
    delete [] newstr;
    return s; 
}

String& String::operator+=(const String& other)
{
    int len = strlen(str_) + strlen(other.str_) + 1;
    char* newstr = new char[len];
    memset(newstr, 0, len);
    strcpy(newstr, str_);
    strcat(newstr, other.str_);

    delete [] this->str_;
    this->str_ = newstr;

    return *this;
}

void String::Display()
{
    cout << str_ << endl;
}

int main(int argc, char** argv) {

    String s1("hello");
    s1.Display();

    String s2 = s1;
    s2.Display();
    
    /*
    String(const char* str="");
    String& operator=(const String& other);
    这里调用的是String(const char* str="")，先产生一个临时对象，然后赋值给s3.

    如果是 explict String(const char* str="");
    则会报错。

    此时需要提供
    String& operator=(const char* other);
    */
    String s3 = "xxxx";
    s3.Display();

    String s4;
    bool nonempty;
    nonempty = !s4;
    cout << nonempty << endl;

    String s5 = "abcdef";
    cout << s5[0] << endl;
    s5[0] = 'A';
    s5.Display();

    //这里是const对象，所以需要如下函数：
    //char& String::operator[](unsigned int n) const
    //而不是char& String::operator[](unsigned int n)
    const String s6 = "ckj";
    cout << s6[0] << endl; 
    //这里我们不希望被改变，因为是const对象
    //此时，需要 const char& String::operator[](unsigned int n)
    //s6[0] = 'A';

    String s7 = s5 + s6;
    s7.Display();

    s5 += s6;
    s5.Display();

    cout << s5 << " " << s6 << endl;

    String s8;
    cin >> s8;
    s8.Display();

    return 0;
}