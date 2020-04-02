#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_
#include<iostream>

using namespace std;


class Enumeration
{
public:
    void fun1()
    {
        cout<<"fun1"<<endl;
    }
    void fun2()
    {
        cout<<"fun2"<<endl;
    }
    void fun3()
    {
        cout<<"fun3"<<endl;
    }
};


class Iteration
{
public:
    virtual void fun_one() = 0;
    virtual void fun_two() = 0;
    virtual void fun_four() = 0;
};



class EnumerationIteration: public Iteration
{
private:
    Enumeration* enumeration;
public:
    EnumerationIteration(Enumeration* e)
    {
        this->enumeration = e;
    }
    void fun_one()
    {
        this->enumeration->fun1();
    }
    void fun_two()
    {
        this->enumeration->fun2();
    }
    void fun_four()
    {
        cout<<"UnsupportedOperation error"<<endl;
    }
};
#endif



