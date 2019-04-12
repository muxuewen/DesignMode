#include <iostream>
#include <list>
using namespace std;

class observer;

class subject
{
public:
	virtual void Attach(observer* obs) = 0;
	virtual void Detach(observer* obs) = 0;
	virtual void Notify() = 0;
	virtual void ShowUser() = 0;
};

class observer
{
public:
	observer()
	{
		m_username = "游客";
	}
	observer(string username) :m_username(username){}

	virtual void Update(const string& news) = 0;

	string m_username;
};


class Concretesubject :public subject
{
public:
	Concretesubject(string name)
	{
		m_name = name;
		cout << m_name.c_str() << "正式发布!" << endl;
	}

	virtual void Attach(observer* obs)
	{
		m_observer.push_back(obs);
		cout << obs->m_username.c_str() << "关注了" << m_name.c_str() << endl;
	}

	virtual void Detach(observer* obs)
	{
		list<observer*>::iterator iter = m_observer.begin();
		for (iter; iter != m_observer.end(); ++iter)
		{
			if (*iter == obs)
			{
				cout << (*iter)->m_username.c_str() << "取消了关注!" << endl;
				m_observer.erase(iter);
				break;
			}
		}
	}

	virtual void Notify()
	{
		cout << m_name.c_str() << "推送了新消息!" << endl;
		list<observer*>::iterator iter = m_observer.begin();
		for (iter; iter != m_observer.end(); ++iter)
		{
			(*iter)->Update(m_info);
		}
	}

	virtual void ShowUser()
	{
		cout << "当前关注的用户有：";
		list<observer*>::iterator iter = m_observer.begin();
		for (iter; iter != m_observer.end(); ++iter)
		{
			cout << (*iter)->m_username.c_str() << " ";
		}
		cout << endl;
	}

	virtual void Release(string news)
	{
		m_info = news;
		cout << m_name.c_str() << "更新了发布内容!" << endl;
	}

	string m_name;
private:
	list<observer*> m_observer;
	string m_info;
};

class Concreteobserver1 : public observer
{
public:
	Concreteobserver1(string name) :observer(name){}
	void Update(const string& news)
	{
		cout << m_username.c_str() << "接收到了推送!"<< news.c_str() << endl;
	}
};

class Concreteobserver2 : public observer
{
public:
	Concreteobserver2(string name) :observer(name){}
	void Update(const string& news)
	{
		cout << "会员用户" << m_username.c_str() << "接收到了推送！" << news.c_str() << endl;
	}
};

int main(void)
{
	Concretesubject* psubject = new Concretesubject("人民日报");

	Concreteobserver1* pCob1 = new Concreteobserver1("小红");
	Concreteobserver1* pCob2 = new Concreteobserver1("小白");
	Concreteobserver2* pCob3 = new Concreteobserver2("小灰");

	psubject->Attach(pCob1);
	psubject->Attach(pCob2);
	psubject->Attach(pCob3);

	psubject->ShowUser();

	psubject->Release("《个人行为规范》");
	psubject->Notify();

	psubject->Detach(pCob2);
	psubject->ShowUser();

	psubject->Release("《新时代的新思想》");
	psubject->Notify();

	//system("PAUSE");
	getchar();
	return 0;
}