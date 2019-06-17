#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Man;
class Woman;

// ��Ϊ
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
		cout << "���˳ɹ�ʱ��������һ����ΰ���Ů�ˣ�" << endl;
	}
	virtual void GetWomanConclusion(Woman* concreteElement)
	{
		cout << "Ů�˳ɹ�ʱ�������и�û�õ����ˣ�" << endl;
	}
};

class Failure :public Action
{
public:
	virtual void GetManConclusion(Man* concreteElement)
	{
		cout << "����ʧ��ʱ��������һ��ΰ���Ů�ˣ�" << endl;
	}
	virtual void GetWomanConclusion(Woman* concreteElement)
	{
		cout << "Ů��ʧ��ʱ�������и�û�е����ˣ�" << endl;
	}
};

// ����
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


// ����ṹ��
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