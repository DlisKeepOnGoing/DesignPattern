#include<stdio.h>

#include<iostream>
using namespace std;




//抽象命令：早餐
class Breakfast
{
public:
    virtual void cooking() = 0;
};



// 命令对应的receiver
class ChangFenChef
{
public:
    void action()
    {
        printf("肠粉厨师制作肠粉\n");
    }
};


//具体命令对应具体的receiver
class ChangFen:public Breakfast
{
private:
    ChangFenChef* receiver;
public:
    ChangFen()
    {
        this->receiver = new ChangFenChef();
    }
    void cooking()
    {
        receiver->action();
    }
};


class ChaoMianChef
{
public:
    void action()
    {
        printf("炒面厨师制作炒面\n");
    }
};



class ChaoMian:public Breakfast
{
private:
    ChaoMianChef* receiver;
public:
    ChaoMian()
    {
        this->receiver = new ChaoMianChef();
    }
    void cooking()
    {
        this->receiver->action();
    }
};



class HeFenChef
{
public:
    void action()
    {
        printf("河粉厨师制作河粉\n");
    }
};



class HeFen:public Breakfast
{
private:
    HeFenChef* receiver;
public:
    HeFen()
    {
        this->receiver = new HeFenChef();
    }
    void cooking()
    {
        printf("河粉厨师制作河粉\n");
    }
};




class Waiter
{
private:
    Breakfast* changfen;
    Breakfast* chaomian;
    Breakfast* hefen;
public: 
    void setChangFen(Breakfast* f) {
		changfen = f;
	}

	void setChaoMian(Breakfast* f) {
		chaomian = f;
	}

	void setHeFen(Breakfast* f) {
		hefen = f;
	}

	void chooseChangFen() {
		changfen->cooking();
	}

	void chooseChaoMain() {
		chaomian->cooking();
	}

	void chooseHeFen() {
		hefen->cooking();
	}
};

int main()
{
    Waiter* waiter = new Waiter();
    Breakfast* chaomian = new ChaoMian();
    waiter->setChaoMian(chaomian);
    waiter->chooseChaoMain();
    waiter->chooseChaoMain();
    return 0;
}




