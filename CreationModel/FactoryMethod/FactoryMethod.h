#ifndef _FACTORYMETHOD_H_
#define _FACTORYMETHOD_H_
#include<iostream>
using namespace std;

// common attribute
class ClothesProduct
{
public:
    ClothesProduct(){}
    void name();
    void buy();
    void wear();
};


// concret product sweater
class SweaterProduct:public ClothesProduct
{
public:
    SweaterProduct()
    {
        name();
        buy();
        wear();
    }
    void name()
    {
        cout<<"sweater is prepared"<<endl;
    }
    void buy()
    {
        cout<<"shaowb buys sweater"<<endl;
    }
    void wear()
    {
        cout<<"shaowb wears sweater"<<endl;
    }
};


class PantsProduct:public ClothesProduct
{
public:
    PantsProduct()
    {
        name();
        buy();
        wear();
    }
    void name()
    {
        cout<<"pants are prepared"<<endl;
    }
    void buy()
    {
        cout<<"shaowb buys pants"<<endl;
    }
    void wear()
    {
        cout<<"shaowb wears pants"<<endl;
    }
};



class TshirtProduct:public ClothesProduct
{
public:
    TshirtProduct()
    {
        name();
        buy();
        wear();
    }
    void name()
    {
        cout<<"T-shirt is prepared"<<endl;
    }
    void buy()
    {
        cout<<"shaowb buys T-shirt"<<endl;
    }
    void wear()
    {
        cout<<"shaowb wears T-shirt"<<endl;
    }
};


class AbstractFactory
{
public:
    virtual ClothesProduct* getClothesProduct() = 0;
};


class SweaterFactory:public AbstractFactory
{
public:
    SweaterFactory()
    {
        cout<<"SweaterFactory"<<endl;
    }
    ClothesProduct* getClothesProduct()
    {
        return new SweaterProduct();
    }
};
class PantsFactory:public AbstractFactory
{
public:
    PantsFactory()
    {
        cout<<"PantsFactory"<<endl;
    }
    ClothesProduct* getClothesProduct()
    {
        return new PantsProduct();
    }
};
class TshirtFactory:public AbstractFactory
{
public:
    TshirtFactory()
    {
        cout<<"TshirtFactory"<<endl;
    }
    ClothesProduct* getClothesProduct()
    {
        return new TshirtProduct();
    }
};
#endif