#define maxChannel 100
#include<iostream>
using namespace std;


class Controller
{
    public:
        virtual void On() = 0;
        virtual void Off() = 0;
        virtual void setChannel(int ch) = 0;
        virtual void setVolume(int vol) = 0;
};


class SonyController:public Controller
{
    public:
        void On()
        {
            cout<<"Sony TV is on"<<endl;
        }
        void Off()
        {
            cout<<"Sony TV is off"<<endl;
        }
        void setChannel(int ch)
        {
            cout<<"Sony TV set channel is "<<ch<<endl;
        }
        void setVolume(int vol)
        {
            cout<<"Sony TV set volume is "<<vol<<endl;
        }
};


class TCLController:public Controller
{
    public:
        void On()
        {
            cout<<"TCL TV is on"<<endl;
        }
        void Off()
        {
            cout<<"TCL TV is off"<<endl;
        }
        void setChannel(int ch)
        {
            cout<<"TCL TV set channel is "<<ch<<endl;
        }
        void setVolume(int vol)
        {
            cout<<"TCL TV set volume is "<<vol<<endl;
        }
};




class TvControllerLabs
{
    protected:
        Controller* controller = NULL;//桥梁
    public:
        TvControllerLabs(Controller* c)
        {
            this->controller = c;
        }
        virtual void OnOff() = 0;
        virtual void nextChannel() = 0;
        virtual void preChannel() = 0;
};


class TvControllerDemandOne: public TvControllerLabs
{
    private:
        static bool isOn;
        static int current_channel; 
    public:
        TvControllerDemandOne(Controller* controller):TvControllerLabs(controller)
        {

        }
        void OnOff()
        {
            if(isOn)
            {
                isOn = false;
                //this->Off();
                this->controller->Off();
            }else
            {
                isOn = true;
                this->controller->On();
            }
        }

        void nextChannel()
        {
            if(current_channel == maxChannel)
            {
                current_channel = 0;
            }else
            {
                current_channel += 1;
            }
            this->controller->setChannel(current_channel);
        }

        void preChannel()
        {
            if(current_channel == 0)
            {
                current_channel = maxChannel;
            }else
            {
                current_channel -= 1;
            }
            this->controller->setChannel(current_channel);
        }
};

bool TvControllerDemandOne::isOn = false;
int TvControllerDemandOne::current_channel = 0;




//增加了新的用户功能
class TvControllerDemandTwo: public TvControllerLabs
{
    private:
        static bool isOn;
        static int current_channel; 
        static int pre_channel;
    public:
        TvControllerDemandTwo(Controller* controller):TvControllerLabs(controller)
        {

        }
        void OnOff()
        {
            if(isOn)
            {
                isOn = false;
                //this->Off();
                this->controller->Off();
            }else
            {
                isOn = true;
                this->controller->On();
            }
        }

        void nextChannel()
        {
            if(current_channel == maxChannel)
            {
                pre_channel = maxChannel;
                current_channel = 0;
            }else
            {
                pre_channel = current_channel;
                current_channel += 1;
            }
            this->controller->setChannel(current_channel);
        }

        void preChannel()
        {
            if(current_channel == 0)
            {
                pre_channel = current_channel;
                current_channel = maxChannel;
            }else
            {
                pre_channel = current_channel;
                current_channel -= 1;
            }
            this->controller->setChannel(current_channel);
        }
        void back()
        {
            cout<<"the back channel is "<< pre_channel<<endl;
            current_channel = pre_channel;
            pre_channel = 0;
        }
};

bool TvControllerDemandTwo::isOn = false;
int TvControllerDemandTwo::current_channel = 0;
int TvControllerDemandTwo::pre_channel = 0;




















