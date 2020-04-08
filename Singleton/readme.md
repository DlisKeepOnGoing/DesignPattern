### 单例模式(Singleton)

单例模式必须满足以下的条件：

1、单例模式的类只能有一个实例

2、单例模式的类只能自己创建这个实例

3、它必须自己向整个系统提供这个实例

而要满足以上三个条件，相应的解决方案：

（1）、所创建的实例是一个静态变量

（2）、构造函数私有化

（3）、向系统提供这个实例的方法也是静态的

```c++
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include<iostream>
using namespace std;
#include <mutex>

class Singleton
{
private:
    static Singleton* _instance;//满足条件1
    static std::mutex m_mutex;//线程安全问题
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
```

注意下多线程安全问题

![1586009143390](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586009143390.png)