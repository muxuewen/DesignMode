#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define SAFE_DELETE(p) if(p){delete p;p = NULL;}

class Request
{
public:
	Request(string msg) :m_msg(msg){}
	string m_msg;
};

class Manager
{
public:
	Manager(){};
	Manager(string name,Manager* temp = NULL) :m_manager(temp)
	{
		m_name = name;
	}

	void SetManager(Manager* tmp)
	{
		m_manager = tmp;
	}

	virtual void DealMsg(Request* Msg) = 0;

protected:
	string m_name;
	Manager* m_manager;
};


class CommonManager : public Manager
{
public:
	CommonManager(string name) :Manager(name)
	{

	}

	void DealMsg(Request* Msg)
	{
		cout << m_name.c_str() << " deal " << Msg->m_msg << endl;
		if (m_manager != NULL)
			m_manager->DealMsg(Msg);
	}
};

class MajorDomo : public Manager
{
public:
	MajorDomo(string name) :Manager(name){}
	void DealMsg(Request* Msg)
	{
		cout << m_name.c_str() << " deal " << Msg->m_msg << endl;
		if (m_manager != NULL)
			m_manager->DealMsg(Msg);
	}
};


int main(void)
{
	Request* req = new Request("leave");
	Manager* com = new CommonManager("zhang");
	Manager* Mjd = new MajorDomo("li");

	com->SetManager(Mjd);
	com->DealMsg(req);


	//system("PAUSE");
	getchar();
	return 0;
}