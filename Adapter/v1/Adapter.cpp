#include<Adapter.h>



int main()
{
    Adaptee* adapee = new Adaptee();
    adapee->StandardVoltage();

    Adapter* adapter = new Adapter(adapee);
    adapter->PhoneVoltage();
    return 0;
}