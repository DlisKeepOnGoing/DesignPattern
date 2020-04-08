### 抽象工厂方法(AbstractFactory)

某一种工厂产生的不止一类的对象，还会产生另外的一类对象。

![1586010045421](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586010045421.png)

```c++
#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include<iostream>
using namespace std;


class AbstractTops
{
public:
    AbstractTops(){};
    void up_body_covered(){};
};

class Sweater:public AbstractTops
{
public:
    Sweater()
    {
        up_body_covered();
    }
    void up_body_covered()
    {
        cout<<"swb wears sweater"<<endl;
    }
};

class Tshirt:public AbstractTops
{
public:
    Tshirt()
    {
        up_body_covered();
    }
    void up_body_covered()
    {
        cout<<"swb wears T-shirt"<<endl;
    }
};
class AbstractBottoms
{
public:
    AbstractBottoms(){};
    void down_body_covered(){};
};


class Trousers:public AbstractBottoms
{
public:
    Trousers()
    {
        down_body_covered();
    }
    void down_body_covered()
    {
        cout<<"swb wears trousers"<<endl;
    }
};

class Shorts:public AbstractBottoms
{
public:
    Shorts()
    {
        down_body_covered();
    }
    void down_body_covered()
    {
        cout<<"swb wears shorts"<<endl;
    }
};


class AbstractFactory
{
public:
    virtual AbstractTops* get_tops() = 0;
    virtual AbstractBottoms* get_bottoms() = 0;
};


class SummerFactory:public AbstractFactory
{
public:
    AbstractTops* get_tops()
    {
        return new Tshirt();
    }
    AbstractBottoms* get_bottoms()
    {
        return new Shorts();
    }
};


class WinterFactory:public AbstractFactory
{
public:
    AbstractTops* get_tops()
    {
        return new Sweater();
    }
    AbstractBottoms* get_bottoms()
    {
        return new Trousers();
    }
};
#endif
```

