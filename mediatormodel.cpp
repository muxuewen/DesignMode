#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define SAFE_DELETE(p) if(p){delete p;p = NULL;}

class Colleague;
// 抽象中介类
class Mediator
{
public:
	virtual void sendmsg(string msg,Colleague* col) = 0;
};

// 抽象同事类
class Colleague
{
public:
	Colleague(Mediator* med) :m_med(med){}
protected:
	Mediator* m_med;
};

// 同事一
class Colleague1 :public Colleague
{
public:
	Colleague1(Mediator* med) :Colleague(med){}
	void sendmsg(string msg)
	{
		m_med->sendmsg(msg, this);
	}
	void Notify(string msg)
	{
		cout << "同事一收到消息：" << msg << endl;
	}
};

class Colleague2 :public Colleague
{
public:
	Colleague2(Mediator* med) :Colleague(med){}
	void sendmsg(string msg)
	{
		m_med->sendmsg(msg, this);
	}

	void Notify(string msg)
	{
		cout << "同事二收到消息:" << msg << endl;
	}
};

class ConcreteMediator : public Mediator
{
public:
	Colleague1* col1;
	Colleague2* col2;

	void sendmsg(string msg, Colleague* col)
	{
		if (col == col1)
			col2->Notify(msg);
		else
			col1->Notify(msg);
	}
};



int main(void)
{
	// 创建一个中介对象
	ConcreteMediator* m = new ConcreteMediator();

	// 让同事认识中介
	Colleague1* col1 = new Colleague1(m);
	Colleague2* col2 = new Colleague2(m);

	// 让中介绑定同事
	m->col1 = col1;
	m->col2 = col2;

	col1->sendmsg("吃了吗？");
	col2->sendmsg("还没呢，你请我吃吗？");

	SAFE_DELETE(m);
	SAFE_DELETE(col1);
	SAFE_DELETE(col2);


	//system("PAUSE");
	getchar();
	return 0;
}