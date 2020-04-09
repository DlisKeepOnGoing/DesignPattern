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