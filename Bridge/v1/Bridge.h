#ifndef _BRIDGE_H_
#define _BRIDGE_H_
#include<iostream>
using namespace std;

#define maxChannel 100

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


class TvController
{
    public:
        virtual void OnOff() = 0;
        virtual void nextChannel() = 0;
        virtual void preChannel() = 0;
};

class SonyTvController: public SonyController, public TvController
{
    private:
        static bool isOn;
        static int current_channel; 
    public:
        void OnOff()
        {
            if(isOn)
            {
                isOn = false;
                //this->Off();
                this->Off();
            }else
            {
                isOn = true;
                this->On();
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
            this->setChannel(current_channel);
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
            this->setChannel(current_channel);
        }
};

bool SonyTvController::isOn = false;
int SonyTvController::current_channel = 0;



class TCLTvController: public TvController, public TCLController
{
    private:
        static bool isOn;
        static int current_channel; 
    public:
        void OnOff()
        {
            if(isOn)
            {
                isOn = false;
                this->Off();
            }else
            {
                isOn = true;
                this->On();
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
            this->setChannel(current_channel);
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
            this->setChannel(current_channel);
        }
};

bool TCLTvController::isOn = false;
int TCLTvController::current_channel = 0;
#endif




















