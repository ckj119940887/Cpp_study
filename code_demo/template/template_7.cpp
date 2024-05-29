#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Singleton
{
public:
    static T& GetInstance()
    {
        Init();
        return *instance_;
    }

private:
    static void Init() 
    {
        if(instance_ == NULL)
        {
            instance_ = new T;
            //退出时调用Destroy
            atexit(Destroy);
        }
    }
    static void Destroy()
    {
        delete instance_;
    }
    Singleton(const Singleton& other);
    Singleton& operator=(const Singleton& other);
    Singleton();
    ~Singleton();

    static T* instance_;
};

template <typename T>
T* Singleton<T>::instance_ = NULL;

class ApplicationImpl
{
public:
    ApplicationImpl()
    {
        cout << "ApplicationImpl ..." << endl;
    }
    ~ApplicationImpl()
    {
        cout << "~ApplicationImpl ..." << endl;
    }
    void Run()
    {
        cout << "Run ..." << endl;
    }
};

typedef Singleton<ApplicationImpl> Application;

int main(int argc, char** argv) {

    Application::GetInstance().Run();
    Application::GetInstance().Run();

    return 0;
}

