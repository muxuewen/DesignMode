#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Man;
class Woman;

// 行为
class Action
{
public:
	virtual void GetManConclusion(Man* concreteElement) = 0;
	virtual void GetWomanConclusion(Woman* concreteElement) = 0;
};

class Success :public Action
{
public:
	virtual void GetManConclusion(Man* concreteElement)
	{
		cout << "男人成功时，背后有一个个伟大的女人！" << endl;
	}
	virtual void GetWomanConclusion(Woman* concreteElement)
	{
		cout << "女人成功时，背后有个没用的男人！" << endl;
	}
};

class Failure :public Action
{
public:
	virtual void GetManConclusion(Man* concreteElement)
	{
		cout << "男人失败时，背后有一个伟大的女人！" << endl;
	}
	virtual void GetWomanConclusion(Woman* concreteElement)
	{
		cout << "女人失败时，背后有个没有的男人！" << endl;
	}
};

// 人类
class Person
{
public:
	virtual void Accept(Action* visitor) = 0;
};

class Man:public Person
{
public:
	virtual void Accept(Action* visitor)
	{
		visitor->GetManConclusion(this);
	}
};

class Woman :public Person
{
public:
	virtual void Accept(Action* visitor)
	{
		visitor->GetWomanConclusion(this);
	}
};


// 对象结构类
class ObjectStructure
{
public:
	void Add(Person* p)
	{
		m_personList.push_back(p);
	}
	void Display(Action* a)
	{
		vector<Person*>::iterator iter = m_personList.begin();
		while(iter != m_personList.end())
		{
			(*iter)->Accept(a);
			iter++;
		}
	}
private:
	vector<Person*> m_personList;
};

int main(void)
{
	ObjectStructure* os = new ObjectStructure();
	os->Add(new Man());
	os->Add(new Woman());

	Success* success = new Success();
	os->Display(success);

	Failure* fl = new Failure();
	os->Display(fl);


	system("PAUSE");

	return 0;
}