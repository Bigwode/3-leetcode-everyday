/*
第一种写法：参考侯捷老师的视频
*/
#include<iostream>

using namespace std;

class A{
public:
    static A& getInstance();

private:
    A(){};
};

A& A::getInstance() {
    static A a;  // 只被创建一次
    return a;
}

int main()
{
    A::getInstance();
    return 0;
};

