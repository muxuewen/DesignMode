#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 Component抽象基类，为组合中的对象声明接口,声明了类共有接口的缺省行为(如这里的Add,Remove,GetChild函数),
 声明一个接口函数可以访问Component的子组件.
*/
class Component
{
public:
	// 纯虚函数，只是提供接口，没有默认的实现
	virtual  void Operation() = 0;

	// 虚函数 提供接口，有默认的实现就是什么都不做
	virtual void Add(Component*){}
	virtual void Remove(Component*){}
	virtual Component* GetChild(int index){ return NULL; }
	virtual ~Component(){}

protected:
	Component(){}
};

// Leaf 是叶子节点，也就是不含有子组件的节点类，所以没有 Add,Remove,GetChild等方法
class Leaf :public Component
{
public:
	// 只实现Operation接口
	void Operation()
	{
		cout << "Leaf::Operation" << endl;
	}
};

// Composite 含有子组件的类
class Composite :public Component
{
public:
	// 实现所有接口
	void Operation()
	{
		cout << "Composite::Operation" << endl;
		vector<Component*>::iterator iter;
		iter = m_comVec.begin();
		for (iter; iter != m_comVec.end(); ++iter)
		{
			(*iter)->Operation();
		}
	}

	void Add(Component* pcom)
	{
		m_comVec.push_back(pcom);
	}

	void Remove(Component* pCom)
	{
		vector<Component*>::iterator iter;
		iter = m_comVec.begin();
		for (iter; iter != m_comVec.end(); ++iter)
		{
			if (*iter == pCom)
			{
				m_comVec.erase(iter);
				break;
			}
		}
	}

	Component* GetChild(int index)
	{
		if (index < 0 || index > m_comVec.size())
			return NULL;
		return m_comVec[index];
	}

private:
	// 采用vectot来保存子组件
	vector<Component*> m_comVec;
};


int main(void)
{
	/*
		不管是Leaf还是composite对象pRoot、pCom都实现了Operation接口，所有可以一致对待，直接调用Operation（）
		体现了 使得用户对单个对象和组合对象的使用 具有一致性
	*/
	Composite* pRoot = new Composite;

	// 组合对象添加叶子节点
	pRoot->Add(new Leaf());

	Leaf* pLeaf1 = new Leaf();
	Leaf* pLeaf2 = new Leaf();

	// 组合对象实现了基类的所有接口 可以进行各种操作 Add Remove GetChild Operation
	Composite* pCom = new Composite();

	pCom->Add(pLeaf1);
	pCom->Add(pLeaf2);

	pCom->Operation();

	// 组合对象添加组合对象
	pRoot->Add(pCom);

	// 执行组合对象 Operation操作
	pRoot->Operation();

	/* 输出结果
	Composite::Operation
	Leaf::Operation
	Leaf::Operation
	Composite::Operation
	Leaf::Operation
	Composite::Operation
	Leaf::Operation
	Leaf::Operation
	*/
	
	//system("PAUSE");
	getchar();
	return 0;
}