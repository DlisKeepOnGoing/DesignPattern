#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include<iostream>
using namespace std;

//适配者
class Adaptee
{
public:
    void StandardVoltage()
    {
        cout<<"中国标准电压为"<<this->v<<"v"<<endl;
    }
    int v = 220;
};

//目标抽象类
class Target
{
public:
    virtual void PhoneVoltage() = 0;
};


//适配器
class Adapter:public Adaptee, public Target
{
public:
    //Adapter(Adaptee* adap)
    //{
    //    this->adaptee = adap;
    //}
    Adapter(){}
    void PhoneVoltage()
    {
        this->v = 36;
        cout<<"适配成手机类的电压"<<this->v<<"v"<<endl;
    }
//private:
//    Adaptee* adaptee;
};
#endif