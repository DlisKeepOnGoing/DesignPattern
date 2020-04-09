#include<iostream>
#include<stdio.h>
using namespace std;


class Subsystem01
{
public:
    void method1()
    {
        printf("子系统01的method1被调用\n");
    }
};


class Subsystem02
{
public:
    void method2()
    {
        printf("子系统02的method2被调用\n");
    }
};


class Subsystem03
{
public:
    void method3()
    {
        printf("子系统03的method3被调用\n");
    }
};

//外观模式
class Facade
{
private:
    Subsystem01* sub01 = new Subsystem01();
    Subsystem02* sub02 = new Subsystem02();
    Subsystem03* sub03 = new Subsystem03();
public:
    void method()
    {
        this->sub01->method1();
        this->sub02->method2();
        this->sub03->method3();
    }
};


//client
int main()
{
    Facade* f = new Facade();
    f->method();
    return 0;
}

