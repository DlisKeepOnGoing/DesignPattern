#include<Builder.h>


int main()
{
    //抽象构建者
    AbstractBuilder* abstract_builder = NULL;
    //指挥者
    Director* director = new Director();
    //产品
    Meal* meal = NULL;


    //指定构造者为A构造者
    abstract_builder = new ConcreteBuilderA();
    director->setBuilder(abstract_builder);
    meal = director->construct();
    meal->showInfo();

    //指定构造者为B构造者
    abstract_builder = new ConcreteBuilderB();
    director->setBuilder(abstract_builder);
    meal = director->construct();
    meal->showInfo();

    return 0;
}