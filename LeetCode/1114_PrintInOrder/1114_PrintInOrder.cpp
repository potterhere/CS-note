// 1114_PrintInOrder.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <condition_variable>
#include <functional>
using namespace std;

class Foo {
public:
    Foo() {

    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        mutex1.lock();

        printFirst();

        mutex1.unlock();

        cond1.notify_one();
    }

    void second(function<void()> printSecond) {

        unique_lock<mutex> lk(mutex1);
        cond1.wait(lk);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        mutex1.unlock();
        cond2.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(mutex1);
        cond2.wait(lk);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    condition_variable cond1;
    condition_variable cond2;
    mutex mutex1;
};

int main()
{
    std::cout << "Hello World!\n";
}
