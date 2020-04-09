#include<AbstractFactory.h>


int main()
{
    cout<<"Abstract Factory Mode"<<endl;
    AbstractTops* at = NULL;
    AbstractBottoms* ab = NULL;
    AbstractFactory* af = NULL;

    //获取夏天的衣服(上衣+下衣)
    af = new SummerFactory();
    at = af->get_tops();
    ab = af->get_bottoms();

    //获取冬天的衣服(上衣+下衣)
    af = new WinterFactory();
    at = af->get_tops();
    ab = af->get_bottoms();

    return 0;
}