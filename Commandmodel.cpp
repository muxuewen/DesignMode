#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define SAFE_DELETE(p) if(p){delete p;p = NULL;}

class Receiver
{
public:
	void runcommand1()
	{
		cout << "first cmd" << endl;
	}
	void runcommand2()
	{
		cout << "second cmd" << endl;
	}
};

class Command
{
public:
	Command(Receiver* recv) :m_receiver(recv){}
	virtual void Execute() = 0;
protected:
	Receiver* m_receiver;
};

class ConcreteCommand1:public Command
{
public:
	ConcreteCommand1(Receiver* recv) :Command(recv){}
	virtual void Execute()
	{
		m_receiver->runcommand1();
	}
};

class ConcreteCommand2 : public Command
{
public:
	ConcreteCommand2(Receiver* recv) :Command(recv){}
	virtual void Execute()
	{
		m_recv->runcommand2();
	}
private:
	Receiver* m_recv;
};

class Invoker
{
public:
	void SetCmd(Command* cmd)
	{
		m_Command.push_back(cmd);
		cout << "add cmd" << endl;
	}
	void Notify()
	{
		if (m_Command.empty())
			return;
		vector<Command*>::iterator iter;
		for (iter = m_Command.begin(); iter != m_Command.end(); ++iter)
		{
			(*iter)->Execute();
		}
	}
private:
	vector<Command*> m_Command;
};

int main(void)
{
	Receiver* pRecv = new Receiver();
	Command* cmd1 = new ConcreteCommand1(pRecv);
	Command* cmd2 = new ConcreteCommand2(pRecv);
	Invoker* pInvk = new Invoker();

	pInvk->SetCmd(cmd1);
	pInvk->SetCmd(cmd2);

	pInvk->Notify();
 

	//system("PAUSE");
	getchar();
	return 0;
}