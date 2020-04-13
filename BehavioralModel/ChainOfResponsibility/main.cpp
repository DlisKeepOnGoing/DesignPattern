#include<iostream>
#include<stdio.h>
using namespace std;

//假如规定学生请假小于或等于 2 天，
//班主任可以批准；小于或等于 7 天，
//系主任可以批准；小于或等于 10 天，
//院长可以批准；其他情况不予批准；
//这个实例适合使用职责链模式实现。

class Handler
{
private:
    Handler* next;
public:
    void setNext(Handler* next)
    {
        this->next = next;
    }
    Handler* getNext()
    {
        return this->next;
    }
    virtual void handleRequest(int leaveDays) = 0;
};


//班主任
class ConcreteHandlerOne:public Handler
{
public:
    void handleRequest(int leaveDays)
    {
        if(leaveDays <= 2)
        {
            printf("班主任允许%d天假期的申请\n", leaveDays);
        }else
        {
            this->getNext()->handleRequest(leaveDays);
        }
    }
};


//系主任
class ConcreteHandlerTwo:public Handler
{
public:
    void handleRequest(int leaveDays)
    {
        if(leaveDays <= 7)
        {
            printf("系主任允许%d天假期的申请\n", leaveDays);
        }else
        {
            this->getNext()->handleRequest(leaveDays);
        }
    }
};

//院长
class ConcreteHandlerThree:public Handler
{
public:
    void handleRequest(int leaveDays)
    {
        if(leaveDays <= 10)
        {
            printf("院长允许%d天假期的申请\n", leaveDays);
        }else
        {
            printf("不允许请假\n");
        }
    }
};




int main()
{
    int leaveDays = 1;
    ConcreteHandlerOne* handle1 = new ConcreteHandlerOne();
    Handler* handle2 = new ConcreteHandlerTwo();
    Handler* handle3 = new ConcreteHandlerThree();
    handle1->setNext(handle2);
    //Handler* temp = handle1->getNext();
    handle2->setNext(handle3);
    handle1->handleRequest(leaveDays);
    return 0;
}