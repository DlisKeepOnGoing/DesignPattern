#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

#include "iostream"
using namespace std;
/*Prototype模式提供了一个通过已存在对象进行新对象创建的接口（Clone）
  Clone()实现和具体的语言相关，在C++中通过拷贝构造函数实现

作用:
用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。

*/

/*Prototype原型基类，定义Clone接口函数
*/
class Prototype
{
protected:
    Prototype();
public:
    virtual Prototype* Clone() const=0;//定义Clone接口，根据不同的派生类来实例化对象
    virtual ~Prototype();
};

//派生自Prototype，实现其接口函数
class ConcretePrototype1:public Prototype
{
public:
    ConcretePrototype1();//构造函数
    ~ConcretePrototype1();//析构函数
    ConcretePrototype1(const ConcretePrototype1&);//拷贝构造函数
    virtual Prototype* Clone() const;//实现基类定义的Clone接口，内部调用拷贝构造函数实现复制功能
};

//派生自Prototype，实现其接口函数
class ConcretePrototype2:public Prototype
{
public:
    ConcretePrototype2();//构造函数
    ~ConcretePrototype2();//析构函数
    ConcretePrototype2(const ConcretePrototype2&);//拷贝构造函数
    virtual Prototype* Clone() const;//实现基类定义的Clone接口，内部调用拷贝构造函数实现复制功能
};
////Prototype
Prototype::Prototype()
{
    cout<<"Prototype"<<endl;
}

Prototype::~Prototype()
{
    cout<<"~Prototype"<<endl;
}

//ConcretePrototype1
ConcretePrototype1::ConcretePrototype1()
{
    cout<<"ConcretePrototype1"<<endl;
}

ConcretePrototype1::~ConcretePrototype1()
{
    cout<<"~ConcretePrototype1"<<endl;
}

ConcretePrototype1::ConcretePrototype1(const ConcretePrototype1& cp)
{
    cout<<"ConcretePrototype1 copy"<<endl;
}

Prototype* ConcretePrototype1::Clone() const
{
    return new ConcretePrototype1(*this);
}

//ConcretePrototype2
ConcretePrototype2::ConcretePrototype2()
{
    cout<<"ConcretePrototype2"<<endl;
}

ConcretePrototype2::~ConcretePrototype2()
{
    cout<<"~ConcretePrototype2"<<endl;
}

ConcretePrototype2::ConcretePrototype2(const ConcretePrototype2& cp)
{
    cout<<"ConcretePrototype2 copy"<<endl;
}

Prototype* ConcretePrototype2::Clone() const
{
    return new ConcretePrototype2(*this);
}
#endif