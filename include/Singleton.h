#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include<iostream>
using namespace std;

#include <mutex>

//单例模式要满足的三个条件
//1,类只能创建一个实例
//2,实例必须要有类来创建
//3,外界必须要访问到这个实例
//4,多线程安全



class Singleton
{
private:
    static Singleton* _instance;//满足条件1
    static std::mutex m_mutex;//满足条件4
    Singleton(){}//满足条件2
public:
    //满足条件3
    static Singleton* GetInstance()
    {
        if(_instance == NULL)
        {
            m_mutex.lock();
            if(_instance == NULL)
            {
                _instance = new Singleton();
                cout<<"创建一个实例"<<endl;
            }
            m_mutex.unlock();
        }
        return _instance;
    }
};

Singleton* Singleton::_instance = 0;
std::mutex Singleton::m_mutex;
#endif



