#include <iostream>
using namespace std;

#define  SAFE_DELETE(p)  if(p) { delete p; p = NULL; }

class context;

class state
{
public:
	virtual void handle(context* p) = 0;
};

class context
{
public:
	context(state* pstate) :m_pstate(pstate){}

	void request()
	{
		if (m_pstate)
			m_pstate->handle(this);
	}

	void SetStutes(state* pstate)
	{
		if (pstate)
			m_pstate = pstate;
	}

private:
	state* m_pstate;
};

class ConcretestateA:public state
{
public:
	void handle(context* p)
	{
		cout << "ConcretestateA" << endl;
	}
};

class ConcretestateB :public state
{
public:
	void handle(context* p)
	{
		cout << "ConcretestateB" << endl;
	}
};


int main(int argc,int argv[])
{
	state* pConA = new ConcretestateA;
	state* pConB = new ConcretestateB;
	context* pct = new context(pConA);

	pct->request(); // ConcretestateA
	pct->SetStutes(pConB);
	pct->request(); // ConcretestateB

	SAFE_DELETE(pct);
	SAFE_DELETE(pConA);
	SAFE_DELETE(pConB);

	system("PAUSE");
	return 0;
}