#include <iostream>
using namespace std;

/*
public:类与外部的接口，任何外部函数可以访问公有类型的数据和函数。
private:只允许本类中的函数访问，而类外部的任何函数都不能访问。
protected:与private类似，其差别表现在继承与派生时对派生类的影响不同。
*/

class Clock {
public:
    void Display();
    void Init(int hour, int minute, int second);
    void update();

private: 
    int hour_;
    int minute_;
    int second_;
};

void Clock::Display(){
    cout << hour_ << ":" << minute_ << ":" << second_ << endl;
}

void Clock::Init(int hour, int minute, int second) {
    hour_ = hour;
    minute_ = minute;
    second_ = second;
}

void Clock::update(){
    second_ = second_ + 1;
}

int main(int argc, char ** args) {

    Clock c;
    c.Init(1,1,1);
    c.Display();

    return 0;
}