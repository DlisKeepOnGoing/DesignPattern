#include<Adapter.h>



int main()
{
    Adaptee* adapee = new Adaptee();
    adapee->StandardVoltage();
    Adapter* adapter = new Adapter();
    adapter->PhoneVoltage();
    return 0;
}