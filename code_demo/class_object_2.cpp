#include <iostream>
using namespace std;

class Test {
public:
    int Add(int, int);

    /*
    void Init();
    void Init(int x);
    void Init(int x, int y);
    void Init(int x, int y, int z);
    */
    // 缺省值
    void Init(int x = 0, int y = 0, int z = 0);

    void Display();

private:
    int x_;
    int y_;
    int z_;
};

void Test::Init(int x = 0, int y = 0, int z = 0) {
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

// inline  函数
inline int Test::Add(int a, int b) {
    return a + b;
}

int main(int argc, char ** args) {

    return 0;
}