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