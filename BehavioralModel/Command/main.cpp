#include<iostream>
#include<stdio.h>
using namespace std;


//接收者
class Receiver {
public: 
    void action() 
    {
		printf("接收者的action()方法被调用...\n");
	}
};


//抽象命令
class Command {
public: 
    virtual void execute() = 0;
};



//具体命令
class ConcreteCommand:public Command {
private:
    Receiver* receiver;
public:
	ConcreteCommand() {
		this->receiver = new Receiver();
	}
	void execute() {
		this->receiver->action();
	}
};



//调用者
class Invoker {
private: 
    Command* command;
public:
    Invoker() {}
	Invoker(Command* cmd) {
		this->command = cmd;
	}

	void setCommand(Command* cmd) {
		this->command = cmd;
	}

	void call() {
		printf("调用者执行命令command...\n");
		this->command->execute();
	}
};


int main()
{
    Command* cmd = new ConcreteCommand();
    //Invoker ir = new Invoker(cmd);
    Invoker* ir = new Invoker();
    ir->setCommand(cmd);
    printf("客户访问调用者的call()方法...\n");
    ir->call();
    return 0;
}


