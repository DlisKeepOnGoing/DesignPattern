#include<iostream>
#include<stdio.h>
using namespace std;



//抽象主题
class Subject {
public:
	virtual void Request() = 0;
};

//真实主题
class RealSubject:public Subject {
public: 
    void Request() 
    {
		printf("访问真实主题方法...\n");
	}
};

//代理
class Proxy:public Subject {
private:
    RealSubject* realSubject;

public:
    void Request() {
		if (realSubject == NULL) {
			realSubject = new RealSubject();
		}
		preRequest();
		realSubject->Request();
		postRequest();
	}

	void preRequest() {
		printf("访问真实主题之前的预处理。\n");
	}

	void postRequest() {
		printf("访问真实主题之后的后续处理。\n");
	}
};


int main()
{
    Proxy* proxy = new Proxy();
	proxy->Request();
    return 0;
}


