#include <iostream>
#include <vector>
using namespace std;

/*
纯虚函数：
基类的接口没办发实现，就将接口定义为纯虚函数，纯虚函数不需要实现。
定义纯虚函数的类称为抽象类，不能实例化。

class 类名
{
    virutal 类型 函数名(参数列表) = 0;
};

构造函数不能是虚函数，析构函数可以是虚函数。

派生类必须实现基类中的纯虚函数，否则将被视为一个抽象类。
*/

class Shape
{
public:
    virtual void Draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void Draw()
    {
        cout << "Circle::Draw() ..." << endl;
    }
    ~Circle()
    {
        cout << "~Circle ..." << endl;
    }
};

class Square: public Shape
{
public:
    void Draw()
    {
        cout << "Square::Draw() ..." << endl;
    }
    ~Square()
    {
        cout << "~Square ..." << endl;
    }
};

void DrawAllShape(const vector<Shape*>& v)
{
    vector<Shape*>::const_iterator it;
    for(it=v.begin(); it!=v.end(); ++it)
    {
        (*it)->Draw();
    }
}

void DeleteAllShape(const vector<Shape*>& v)
{
    vector<Shape*>::const_iterator it;
    for(it=v.begin(); it!=v.end(); ++it)
    {
        //如果不定义虚析构函数，两个派生类的析构函数就不会被调用
        delete(*it);
    }
}

// 简单工厂模式
class ShapeFactory
{
public:
    static Shape* CreateShape(const string& name)
    {
        Shape* ps = NULL;
        if(name == "Circle")
        {
            ps = new Circle;
        }
        else if(name == "Square")
        {
            ps = new Square;
        }
        return ps;
    }
};

int main()
{
    vector<Shape*> v;
    Shape* ps;
    ps = new Circle;
    v.push_back(ps);
    ps = new Square;
    v.push_back(ps);

    DrawAllShape(v);
    DeleteAllShape(v);

    return 0;
}