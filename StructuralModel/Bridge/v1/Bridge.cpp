#include<Bridge.h>



int main()
{
    SonyTvController* sony = new SonyTvController();
    sony->OnOff();
    sony->nextChannel();
    sony->nextChannel();
    sony->preChannel();

    TCLTvController* tcl = new TCLTvController();
    tcl->OnOff();
    tcl->nextChannel();
    tcl->preChannel();
    tcl->preChannel();


    return 0;
}