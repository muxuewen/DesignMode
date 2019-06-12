#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �������վ
class WebSite
{
public:
	virtual void Use() = 0;
};

// ����Ĺ�����վ
class ConcreteWebSite :public WebSite
{
public:
	ConcreteWebSite(string name) : m_name(name)
	{
	}

	virtual void Use()
	{
		cout << "��վ���ࣺ" << m_name.c_str() << endl;
	}
private:
	string m_name;
};

// ���������վ
class UnShareWebSite :public  WebSite
{
public:
	UnShareWebSite(string name) :m_name(name){}

	virtual void Use()
	{
		cout << "���������վ��" << m_name.c_str() << endl;
	}
private:
	string m_name;
};

// ��վ�����࣬���д�Ź������վwebsite����
class WebFactoyy
{
public:
	WebFactoyy(string name)
	{
		m_website.push_back(new ConcreteWebSite(name));
	}

	WebSite* GetWeb()
	{
		vector<WebSite*>::iterator iter = m_website.begin();
		if (iter != m_website.end())
		{
			return *iter;
		}
		else
			return NULL;
	}

private:
	vector<WebSite*> m_website;
};



int main(void)
{
	WebFactoyy* f = new WebFactoyy("����1");
	WebSite* Ws = f->GetWeb();
	Ws->Use();

	WebSite* Ws2 = f->GetWeb();
	Ws2->Use();

	// ���������վ
	WebSite* Ws3 = new UnShareWebSite("����2");
	Ws3->Use();


	system("PAUSE");

	return 0;
}