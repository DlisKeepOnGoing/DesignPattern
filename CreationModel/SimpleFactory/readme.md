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