#include<FactoryMethod.h>



int main()
{
    ClothesProduct* pro = NULL;
    AbstractFactory* fac = NULL;
    fac = new SweaterFactory();
    pro = fac->getClothesProduct();

    fac = new PantsFactory();
    pro = fac->getClothesProduct();

    fac = new TshirtFactory();
    pro = fac->getClothesProduct();

    return 0;
}