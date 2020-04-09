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