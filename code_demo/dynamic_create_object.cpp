#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

/*
反射：动态获取类型信息(方法与属性),动态创建对象，动态调用对象的方法，动态操作对象的属性。
需要给类添加元数据。
*/

/*
动态创建对象：对原有的类不做任何修改，只需要增加一个宏。
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

typedef void* (*CREATE_FUNC)();

class DynObjectFactory
{
public:
    static void* CreateObject(const string& name)
    {
        map<string, CREATE_FUNC>::const_iterator it;
        it = mapCls_.find(name);
        if(it == mapCls_.end())
            return 0;
        else
            return it->second();
    }

    static void Register(const string& name, CREATE_FUNC func)
    {
        mapCls_[name] = func;
    }
    
private:
    static map<string, CREATE_FUNC> mapCls_;
};

map<string, CREATE_FUNC> DynObjectFactory::mapCls_;

class Register
{
public:
    Register(const string& name, CREATE_FUNC func)
    {
        DynObjectFactory::Register(name,func);
    }
};

//##是字符串拼接操作
//#class_name直接将class_name变成字符串
#define REGISTER_CLASS(class_name) \
class class_name##Register { \
public: \
    static void* NewInstance() \
    { \
        return new class_name; \
    } \
private: \
    static Register reg_; \
}; \
Register class_name##Register::reg_(#class_name, class_name##Register::NewInstance)

REGISTER_CLASS(Circle);
REGISTER_CLASS(Square);

int main()
{
    vector<Shape*> v;

    Shape* ps;
    ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Circle"));
    v.push_back(ps);
    ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Square"));
    v.push_back(ps);

    DrawAllShape(v);
    DeleteAllShape(v);

    return 0;
}