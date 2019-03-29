#include <iostream>
using namespace std;

class COperation
{
public:
	int m_nFirst;
	int m_nSecond;
	virtual double GetResult()
	{
		double result = 0;
		return result;
	}
};

class Add :public COperation
{
public:
	Add(int x, int y) 
	{
		m_nFirst = x;
		m_nSecond = y;
	}
	virtual double GetResult()
	{
		double result = m_nFirst + m_nSecond;
		return result;
	}
};

class Minus :public COperation
{
public:
	Minus(int x, int y)
	{
		m_nFirst = x;
		m_nSecond = y;
	}
	virtual double GetResult()
	{
		double result = m_nFirst - m_nSecond;
		return result;
	}
};

class Mult :public COperation
{
public:
	Mult(int x, int y)
	{
		m_nFirst = x;
		m_nSecond = y;
	}
	virtual double GetResult()
	{
		double result = m_nFirst * m_nSecond;
		return result;
	}
};

class Division :public COperation
{
public:
	Division(int x, int y)
	{
		m_nFirst = x;
		m_nSecond = y;
	}
	virtual double GetResult()
	{
		double result = m_nFirst / m_nSecond;
		return result;
	}
};

class Context
{
private:
	COperation* op;
public:
	Context(COperation* op)
	{
		this->op = op;
	}
	virtual double Getresult()
	{
		return op->GetResult();
	}
};

int main(void)
{
	while (1)
	{
		int a, b;
		char c;
		cout << "��������Ҫ������������������� 0 0 ������" << endl;
		cin >> a >> b;
		if (0 == a && 0 == b)
		{
			cout << "��������������˳���" << endl;
			break;
		}
		cout << "�������������" << endl;
		cin >> c;
		switch (c)
		{
		case '+':
			{
					Context* con = new Context(new Add(a,b));
					cout << con->Getresult() << endl;
			}
			break;
		case '-':
			{
					Context* con = new Context(new Minus(a,b));
					cout << con->Getresult() << endl;
			}
			break;
		case '*':
			{
					Context* con = new Context(new Mult(a, b));
					cout << con->Getresult() << endl;
			}
			break;
		case '/':
			{
					Context* con = new Context(new Division(a, b));
					cout << con->Getresult() << endl;
			}
			break;
		default:
			break;
		}
	}

	//system("PAUSE");
	getchar();
	return 0;
}