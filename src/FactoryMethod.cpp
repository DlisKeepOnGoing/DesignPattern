#include<FactoryMethod.h>



int main()
{
    ClothesProduct* pro = NULL;

    SweaterFactory* s_fac = new SweaterFactory();
    pro = s_fac->getClothesProduct();

    PantsFactory*  p_fac = new PantsFactory();
    pro = p_fac->getClothesProduct();

    TshirtFactory* t_fac = new TshirtFactory();
    pro = t_fac->getClothesProduct();

    return 0;
}