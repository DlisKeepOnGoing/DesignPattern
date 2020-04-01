#ifndef _BUILDER_H_
#define _BUILDER_H_

#include<iostream>
using namespace std;

class Meal{
public:
    Meal(){}
    void setBurger(string b)
    {
        this->burger = b;
    }
    void setChips(string c)
    {
        this->chips = c;
    }
    void setDrink(string d)
    {
        this->drink = d;
    }
    void showInfo()
    {
        cout<<this->burger<<endl;
        cout<<this->chips<<endl;
        cout<<this->drink<<endl;
    }
private:
    string burger;
    string chips;
    string drink;
};

class AbstractBuilder{
public:
    AbstractBuilder()
    {
        meal = new Meal();
    }
    virtual void buildBurger() = 0;
    virtual void buildChips() = 0;
    virtual void buildDrink() = 0;
    virtual Meal* get_meal() = 0;
    Meal* meal;
};


class ConcreteBuilderA:public AbstractBuilder
{
public:
    ConcreteBuilderA()
    {
        cout<<"ConcreteBuilderA"<<endl;
    }
    void buildBurger()
    {
        this->meal->setBurger("A_Burger");
    }
    void buildChips()
    {
        this->meal->setChips("A_Chips");
    }
    void buildDrink()
    {
        this->meal->setDrink("A_Drink");
    }
    Meal* get_meal()
    {
        return this->meal;
    }
};


class ConcreteBuilderB:public AbstractBuilder
{
public:
    ConcreteBuilderB()
    {
        cout<<"ConcreteBuilderB"<<endl;
    }
    void buildBurger()
    {
        this->meal->setBurger("B_Burger");
    }
    void buildChips()
    {
        this->meal->setChips("B_Chips");
    }
    void buildDrink()
    {
        this->meal->setDrink("B_Drink");
    }
    Meal* get_meal()
    {
        return this->meal;
    }
};
class Director
{
public:
    Director(){}
    void setBuilder(AbstractBuilder* ibuilder)
    {
        this->builder = ibuilder;
    }
    Meal* construct()
    {
        this->builder->buildBurger();
        this->builder->buildChips();
        this->builder->buildDrink();
        return this->builder->get_meal();
    }
private:
    AbstractBuilder* builder;
};
#endif
