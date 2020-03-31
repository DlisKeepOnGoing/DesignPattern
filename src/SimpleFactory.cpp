#include<SimpleFactory.h>



int main()
{
    cout<<"simple factory mode"<<endl;
    ClothesProduct* pro = NULL;
    Factory* factory = new Factory();
    pro = factory->getClothesProduct("Sweater");
    pro = factory->getClothesProduct("Pants");
    pro = factory->getClothesProduct("Tshirt");
    return 0;
}