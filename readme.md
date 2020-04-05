# 创建型模式

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



### 简单工厂(SimpleFactory)

#### ![1586009341669](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586009341669.png)

简单工厂的核心就在于Factory类的getClothesProduct的方法

```c++
class Factory
{
public:
    ClothesProduct* getClothesProduct(string nameProduct)
    {
        ClothesProduct* p_product = NULL;
        if(nameProduct == "Sweater")
        {
            p_product = new SweaterProduct();
        }else if(nameProduct == "Pants")
        {
            p_product = new PantsProduct();
        }else if(nameProduct == "Tshirt")
        {
            p_product = new TshirtProduct();
        }
        return p_product;
    }
};
```

简单工厂这种设计模式违背了软件设计模式中的开闭原则，“对扩展开放，对修改关闭”，例如当需要修改产品的名字，你就需要对Factory类里面的getClothesProduct方法进行修改。

### 工厂方法(FactoryMethod)

工厂方法就是对简单工厂方法的一种改进

某一种工厂就只产生一类的商品，这样在增加一个商品的时候，增加一个工厂便可以。

![1586062009683](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586062009683.png)

### 抽象工厂方法(AbstractFactory)

某一种工厂产生的不止一类的对象，还会产生另外的一类对象。

![1586010045421](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586010045421.png)

```c++
#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include<iostream>
using namespace std;


class AbstractTops
{
public:
    AbstractTops(){};
    void up_body_covered(){};
};

class Sweater:public AbstractTops
{
public:
    Sweater()
    {
        up_body_covered();
    }
    void up_body_covered()
    {
        cout<<"swb wears sweater"<<endl;
    }
};

class Tshirt:public AbstractTops
{
public:
    Tshirt()
    {
        up_body_covered();
    }
    void up_body_covered()
    {
        cout<<"swb wears T-shirt"<<endl;
    }
};
class AbstractBottoms
{
public:
    AbstractBottoms(){};
    void down_body_covered(){};
};


class Trousers:public AbstractBottoms
{
public:
    Trousers()
    {
        down_body_covered();
    }
    void down_body_covered()
    {
        cout<<"swb wears trousers"<<endl;
    }
};

class Shorts:public AbstractBottoms
{
public:
    Shorts()
    {
        down_body_covered();
    }
    void down_body_covered()
    {
        cout<<"swb wears shorts"<<endl;
    }
};


class AbstractFactory
{
public:
    virtual AbstractTops* get_tops() = 0;
    virtual AbstractBottoms* get_bottoms() = 0;
};


class SummerFactory:public AbstractFactory
{
public:
    AbstractTops* get_tops()
    {
        return new Tshirt();
    }
    AbstractBottoms* get_bottoms()
    {
        return new Shorts();
    }
};


class WinterFactory:public AbstractFactory
{
public:
    AbstractTops* get_tops()
    {
        return new Sweater();
    }
    AbstractBottoms* get_bottoms()
    {
        return new Trousers();
    }
};
#endif
```

### 原型方法(Prototype)

原型方法主要的适用场景是：实例的克隆

一般的克隆是通过类来克隆，原型方法是用对象来客隆的。

![1586062777612](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586062777612.png)



```c++
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
```



# 结构型模式

### 适配器(Adapter)

适配器软件设计模式，很简单，就是现在有一个三孔的插头，如何当成两孔的插头来用，这种设计模式经常被用来处理不兼容的问题，一般包含Adapter，Adaptee以及Target三个对象。Adapter为适配器，Adaptee为被适配的对象，Target为Adapter适配Adaptee最终的结果对象。简而言之，就是Adapter将Adaptee变成了Target。

方法一：

将对象以组合的方式，即将Adaptee的对象以组合的方式组合到Adapter类里面。（**对象组合**）

![1586008030823](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586008030823.png)

方法二：

以类继承的方式，使得Adapter直接调用父类Adaptee的方法，从而实现Target的方法。（**类继承**）

![1586008678509](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586008678509.png)

举例：

将Enumeration去适配Iteration，Iteration是一个接口。

![1586008409260](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586008409260.png)

### 桥接模式(Bridge)

**提出问题：**

​	假如你现在是某一家遥控器公司的职员，公司接到一个任务：根据用户的需求生产索尼电视的遥控器。

​	大家公认的遥控器一般有一个接口，包含遥控器本身的各种功能，如图所示，遥控器抽象类Controller，包含On()，Off()等方法，每一个厂商可以实现Controller的方法。但是用户的需求不可能与Controller里面的方法相匹配，所以公司会设置用户要求的基础类TVController，里面包含OnOff()、nextChannel()、preChannel()等方法。现在公司要求你根据用户的需求来实现索尼电视的遥控器。

![1585920605175](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1585920605175.png)

**解决问题：**

​	最简单的时候可以通过继承， 即让TVController继承SonyController，TVController通过调用SonyController里面已经实现的方法来实现自身的功能。如果公司又来了一个订单，让你实现TCL电视的遥控器，那么你可以又要写一个TVController去继承TCLController。但是这样写肯定不好，你也知道，万一用户的需求变了，公司服务的电视机厂商变多了，你应该怎么办？

![1585920667355](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1585920667355.png)

**优化问题：**

​	桥接模式就这样出来啦，桥接模式，顾名思义，桥梁连接两端，这两端分别是抽象和实现。下面就上面的例子来分别介绍哪些是抽象，哪些是实现。上述例子，很明显有两个维度，用户不停变化的需求和公司接下来要合作的层出不穷的电视机厂商，桥接模式就是将这两种维度给它分来，如下图所示，图的右边是各个不同厂商在生产电视的时候提供的遥控器实现的接口，每一家厂商对于遥控器的同一种功能的配置参数不一样，右边的内容即是实现。图的左边，首先将用户的需求抽象成一个基础类TVControllerLabs，该接口中满足了普通用户对于遥控器的最基本的期待，同时，将Controller作为一个成员变量，以组合的方式组合到该类中，使用基类的指针指向子类对象。接着当用户的需求有改变的时候，便可以做一版TvControllerDemandTwo，从而可以实现TVControllerLabs的基本功能，同时将指定的厂商实现的遥控器对象传入Controller，调用该对象的方法便可以完成用户多种多样的需求。这样做，成功的将用户的需求与厂商分离开，使得该问题在两个维度上面都比较容易扩展。

![1585921114772](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1585921114772.png)

桥接模式的关键点：

桥接的目的是分离抽象与实现，使得抽象和实现可以独立变化。

系统有多维角度分类时，而每一种分类又有可能变化，考虑使用桥接模式。左边抽象，右边实现。

### 组合模式

#### 组合（Composite）模式的定义：

​	有时候又叫做**部分-整体模式**，它是一种将对象组合成树状的层次结构的模式，用来表示”部分-整体“的关系，使得用户对于单个对象和组合对象具有一致的访问性。

组合模式的主要优点：

​	a）组合模式使得客户端代码可以一致的处理单个对象和组合对象，无须关心自己处理的是单个对象，还是组合对象，这简化了客户端代码。

​	b）更容易在组合体内加入新的对象，客户端不会因为加入了新的对象而更改源代码，从而满足“开闭原则”。

组合模式的主要缺点：

​	a）设计较复杂，客户端需要花更多的时间理清类之间的层次关系。

​	b）不容易限制容器中的构件。

#### 组合模式的结构与实现

组合模式所包含的以下的主要角色：

​	a）抽象构件（Component）角色：它的主要作用是为树叶构件和树枝构件声明公共的接口，并实现它们的默认行为。透明式组合模式，安全式组合模式

​	b）树叶构件（Leaf）

​	c）树枝构件（Composite）

![1586073142762](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586073142762.png)

![1586073221661](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586073221661.png)

![1586073267530](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586073267530.png)

![1586089681542](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586089681542.png)

安全模式：

![1586088362572](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586088362572.png)

举个例子：

![1586091339466](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586091339466.png)



采用安全式的设计模式：

![1586091450991](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586091450991.png)

![1586092388722](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1586092388722.png)