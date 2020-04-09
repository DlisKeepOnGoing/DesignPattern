#include<iostream>
#include<stdio.h>
#include<unordered_map>
using namespace std;


//非共享角色
class UnsharedConcreteFlyweight
{
private:
    string info;
public:
    UnsharedConcreteFlyweight(string info)
    {
        this->info = info;
    }
    void setInfo(string info)
    {
        this->info = info;
    }
    string getInfo()
    {
        return this->info;
    }
};

//抽象享元角色
class Flyweight
{
public:
    virtual void operation(UnsharedConcreteFlyweight* state) = 0;
};


class ConcreteFlyweight:public Flyweight
{
private:
    string key;
public:
    ConcreteFlyweight(string key)
    {
        this->key = key;
    }
    void operation(UnsharedConcreteFlyweight* state)
    {
        printf("具体享元%s被调用\n", this->key.c_str());
        printf("非享元的信息是%s\n", state->getInfo().c_str());
    }
};


class FlyweightFactory
{
private:
    unordered_map<string, Flyweight*> flyweights;
public:
    Flyweight* getFlyweight(string key)
    {
        if(flyweights.find(key) != flyweights.end())
        {
            //找到相应的flyweight
            printf("具体享元%s已经存在，被成功调取\n", key.c_str());
            return flyweights[key];
        }else
        {
            flyweights[key] = new ConcreteFlyweight(key);
            printf("具体享元被创建，被成功调取\n", key.c_str());
            return flyweights[key];
        }
    }
};


int main()
{
    FlyweightFactory* fac = new FlyweightFactory();
    Flyweight* f1 = fac->getFlyweight("a");


    
    Flyweight* f2 = fac->getFlyweight("a");
    Flyweight* f3 = fac->getFlyweight("a");

    f1->operation(new UnsharedConcreteFlyweight("第一次调用a"));
    f2->operation(new UnsharedConcreteFlyweight("第二次调用a"));

    return 0;
}