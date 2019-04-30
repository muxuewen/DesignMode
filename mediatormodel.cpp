#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define SAFE_DELETE(p) if(p){delete p;p = NULL;}

class Colleague;
// �����н���
class Mediator
{
public:
	virtual void sendmsg(string msg,Colleague* col) = 0;
};

// ����ͬ����
class Colleague
{
public:
	Colleague(Mediator* med) :m_med(med){}
protected:
	Mediator* m_med;
};

// ͬ��һ
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
		cout << "ͬ��һ�յ���Ϣ��" << msg << endl;
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
		cout << "ͬ�¶��յ���Ϣ:" << msg << endl;
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
	// ����һ���н����
	ConcreteMediator* m = new ConcreteMediator();

	// ��ͬ����ʶ�н�
	Colleague1* col1 = new Colleague1(m);
	Colleague2* col2 = new Colleague2(m);

	// ���н��ͬ��
	m->col1 = col1;
	m->col2 = col2;

	col1->sendmsg("������");
	col2->sendmsg("��û�أ������ҳ���");

	SAFE_DELETE(m);
	SAFE_DELETE(col1);
	SAFE_DELETE(col2);


	//system("PAUSE");
	getchar();
	return 0;
}