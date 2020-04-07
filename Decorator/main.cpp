#include<iostream>
#include<stdio.h>
using namespace std;


//抽象构建
class Component
{
public:
    virtual void Operation() = 0;
};


//具体构建
class ConcreteComponent: public Component
{
public:
    ConcreteComponent()
    {
        printf("具体构建角色被调用\n");
    }
    void Operation()
    {
        printf("具体构建角色的operation方法被调用\n");
    }
};

//抽象装饰
class Decotator: public Component
{
public:
    Decotator(Component* com)
    {
        this->component = com;
    }
    void Operation()
    {
        this->component->Operation();
    }
private:
    Component* component;
};

//具体装饰
class ConcreteDecorator: public Decotator
{
public:
    ConcreteDecorator(Component* c):Decotator(c)
    {

    }
    void Operation()
    {
        this->pre_function();
        Decotator::Operation();
        this->added_function();
    }
    void pre_function()
    {
        printf("具体构建角色的pre_operation方法被调用\n");
    }
    void added_function()
    {
        printf("具体构建角色的added_operation方法被调用\n");
    }
};


int main()
{
    Component* component = new ConcreteComponent();
    component->Operation();
    Component* concretedecorator = new ConcreteDecorator(component);
    concretedecorator->Operation();
    return 0;
}



