#include<iostream>
using namespace std;

#include<stdio.h>
#include<vector>
#include<string>

//抽象构件
class Component
{
public:
	virtual void operation() = 0;
};


//树叶的构件
class Leaf : public Component
{
private:
	string name;
public:
	Leaf(string name)
	{
		this->name = name;
	}
	void operation()
	{
		//printf("树叶%s被访问", name);
		cout << "树叶" << name << "被访问" << endl;
	}
};

class Composite :public Component
{
private:
	string name;
	vector<Component*> componentList;
public:
	void add(Component* c)
	{
		componentList.push_back(c);
	}
	void remove(Component* c)
	{
		//在vector容器中将元素删掉
		// for (int i = 0; i < componentList.size(); i++) {
		// 	if (componentList[i]->getName() == c->getName()) {
		// 		componentList.erase(componentList.begin() + i);
		// 		break;
		// 	}
		// }
        // 根据需求进行实现
	}
	Component* getChild(int i)
	{
		return (Component*)componentList[i];
	}
	void operation()
	{
		//printf("%s\n", this->name.c_str())componentList;
		//cout << this->name << endl;
		for (int i = 0; i < componentList.size(); i++)
		{
			((Component*)componentList[i])->operation();
		}
	}
};


int main()
{
	
	Composite* c0 = new Composite();
	Composite* c1 = new Composite();
	Leaf* leaf1 = new Leaf("1");
	Leaf* leaf2 = new Leaf("2");
	Leaf* leaf3 = new Leaf("3");
	
	c0->add(leaf1);
	c0->add(c1);
	c1->add(leaf2);
	c1->add(leaf3);

	c0->operation();
	return 0;
}