#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 抽象的网站
class WebSite
{
public:
	virtual void Use() = 0;
};

// 具体的共享网站
class ConcreteWebSite :public WebSite
{
public:
	ConcreteWebSite(string name) : m_name(name)
	{
	}

	virtual void Use()
	{
		cout << "网站分类：" << m_name.c_str() << endl;
	}
private:
	string m_name;
};

// 不共享的网站
class UnShareWebSite :public  WebSite
{
public:
	UnShareWebSite(string name) :m_name(name){}

	virtual void Use()
	{
		cout << "不共享的网站：" << m_name.c_str() << endl;
	}
private:
	string m_name;
};

// 网站工厂类，用有存放共享的网站website对象
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
	WebFactoyy* f = new WebFactoyy("测试1");
	WebSite* Ws = f->GetWeb();
	Ws->Use();

	WebSite* Ws2 = f->GetWeb();
	Ws2->Use();

	// 不共享的网站
	WebSite* Ws3 = new UnShareWebSite("测试2");
	Ws3->Use();


	system("PAUSE");

	return 0;
}