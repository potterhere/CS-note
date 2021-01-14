// CreateMode_Singleton.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
public:
    static Singleton* GetInstance()
    {
        static Singleton instance;
        return &instance;
    }

public:
    Singleton(const Singleton&) = delete;

private:
    Singleton() {};
private:
    static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

int main()
{
    {
        Singleton* singleton = Singleton::GetInstance();
        cout << "0x" << hex << singleton << endl;
    }

    {
        Singleton* singleton = Singleton::GetInstance();
        cout << "0x" << hex << singleton << endl;
    }

    {
        Singleton* singleton = Singleton::GetInstance();
        cout << "0x" << hex << singleton << endl;
    }
}
