#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 迭代器接口类
class Iterator
{
public:
	Iterator(){};
	virtual ~Iterator(){};
	virtual string First() = 0;
	virtual string Next() = 0;
	virtual string GetCur() = 0;
	virtual bool Isend() = 0;
};

// 聚合对象接口类
class Aggregate
{
public:
	virtual int Count() = 0;
	virtual void Push(const string& strValue) = 0;
	virtual string Pop(const int nIndex) = 0;
	virtual Iterator* CreateIterator() = 0;
};

// 具体迭代器实现类
class ConcreteIterator :public Iterator
{
public:
	ConcreteIterator(Aggregate* aggregate) :m_nCurrent(0)
	{
		m_aggregate = aggregate;
	}
	~ConcreteIterator()
	{
		if (m_aggregate != NULL)
		{
			delete m_aggregate;
			m_aggregate = NULL;
		}
	}
	string First()
	{
		return m_aggregate->Pop(0);
	}

	string Next()
	{
		string strRet;
		m_nCurrent++;
		if (m_nCurrent < m_aggregate->Count())
		{
			strRet = m_aggregate->Pop(m_nCurrent);
		}
		return strRet;
	}

	string GetCur()
	{
		return m_aggregate->Pop(m_nCurrent);
	}

	bool Isend()
	{
		return ((m_nCurrent >= m_aggregate->Count()) ? true : false);
	}

private:
	Aggregate* m_aggregate;
	int m_nCurrent;
};

// 具体的聚合对象实现类
class ConcreteAggregate :public Aggregate
{
public:
	ConcreteAggregate() :m_pIter(NULL)
	{
		m_vecItems.clear();
	}
	~ConcreteAggregate()
	{
		if (m_pIter != NULL)
		{
			delete m_pIter;
			m_pIter = NULL;
		}
	}
	int Count()
	{
		return m_vecItems.size();
	}

	void Push(const string& strValue)
	{
		m_vecItems.push_back(strValue);
	}

	string Pop(const int nIndex)
	{
		string strRet;
		if (nIndex < Count())
		{
			strRet = m_vecItems[nIndex];
		}
		return strRet;
	}

	Iterator* CreateIterator()
	{
		if (m_pIter == NULL)
		{
			m_pIter = new ConcreteIterator(this);
		}
		return m_pIter;
	}

private:
	vector<string> m_vecItems;
	Iterator* m_pIter;
};

int main(void)
{
	// 创建一个聚合对象
	ConcreteAggregate* pName = NULL;
	pName = new ConcreteAggregate();

	//  向聚合类中压入数据
	pName->Push("Hello");
	pName->Push("word");
	pName->Push("cxue");

	// 定义一个迭代器 指向聚合对象
	Iterator* iter = pName->CreateIterator();

	// 获取第一个元素数据
	string str = iter->First();
	cout << str.c_str() << endl;

	// 迭代器指向下一个数据
	iter->Next();
	// 获取当前位置的数据
	cout << iter->GetCur() << endl;

	// 判断迭代器是否指向 当前聚合对象的尾部
	while (!iter->Isend())
	{
		cout << iter->GetCur() << endl;
		iter->Next();
	}
	cout << "迭代器已指向聚合对象尾部" << endl;
	
	//system("PAUSE");
	getchar();
	return 0;
}