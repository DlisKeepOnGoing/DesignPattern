#include<Bridge.h>


int main()
{
    Controller* controller = new SonyController();
    TvControllerDemandOne* demend_one = new TvControllerDemandOne(controller);
    demend_one->OnOff();
    demend_one->nextChannel();
    demend_one->nextChannel();
    demend_one->nextChannel();
    demend_one->nextChannel();
    demend_one->preChannel();


    TvControllerDemandTwo* demend_two = new TvControllerDemandTwo(controller);
    demend_two->OnOff();
    demend_two->nextChannel();
    demend_two->back();
    demend_two->nextChannel();
    demend_two->nextChannel();
    demend_two->preChannel();
    return 0;
}