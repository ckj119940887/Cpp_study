#include <iostream>
using namespace std;

/*
const 成员函数：不会修改对象的状态，只能访问数据成员的值，不能修改它
*/

class Test
{
public:
    Test(int x) : x_(x), outputTimes_(0)
    {

    }
    int GetX() const
    {
        cout << "const function" << endl;
        return x_;
    }

    // const 成员函数支持重载
    int GetX()
    {
        return x_;
    }

    void Output() const
    {
        cout << "x=" << x_ << endl;
        outputTimes_++;
    }

    int GetOutputTimes() const
    {
        return outputTimes_;
    }

private:
    int x_;
    // const 成员函数可以修改被mutable修饰的成员变量
    mutable int outputTimes_;
};

int main(int argc, char** argv) {
    //const 成员对象
    //const 对象只能被const 成员函数访问
    const Test t(19);
    cout << t.GetX() << endl;

    return 0;
}