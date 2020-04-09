#ifndef _SIMPLEFACTORY_H_
#define _SIMPLEFACTORY_H_
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


class Factory
{
public:
    ClothesProduct* getClothesProduct(string nameProduct)
    {
        ClothesProduct* p_product = NULL;
        if(nameProduct == "Sweater")
        {
            p_product = new SweaterProduct();
        }else if(nameProduct == "Pants")
        {
            p_product = new PantsProduct();
        }else if(nameProduct == "Tshirt")
        {
            p_product = new TshirtProduct();
        }
        return p_product;
    }
};
#endif
