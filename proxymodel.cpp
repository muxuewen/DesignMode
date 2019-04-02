#include <iostream>
using namespace std;


class girl
{
public:
	girl(char* name) :m_name(name)
	{

	}
	char* getname()
	{
		return m_name;
	}
private:
	char* m_name;
};

class givegirl
{
public:
	virtual void giveDolls() = 0;
	virtual void giveFlowers() = 0;
	virtual void giveChocolate() = 0;
};

class Puisuit :public givegirl
{
public:
	Puisuit(girl* pgirl) :m_girl(pgirl){}
	virtual void giveDolls()
	{
		cout << "给" << m_girl->getname() << "送玩具" << endl;
	}
	virtual void giveFlowers()
	{
		cout << "给" << m_girl->getname() << "送鲜花" << endl;
	}
	virtual void giveChocolate()
	{
		cout << "给" << m_girl->getname() << "送巧克力" << endl;
	}
private:
	girl* m_girl;
};

class Proxy :public givegirl
{
public:
	Proxy(Puisuit* puisuit) :m_puisuit(puisuit){}
	virtual void giveDolls()
	{
		m_puisuit->giveDolls();
	}
	virtual void giveFlowers()
	{
		m_puisuit->giveFlowers();
	}
	virtual void giveChocolate()
	{
		m_puisuit->giveChocolate();
	}
private:
	Puisuit* m_puisuit;
};


int main(void)
{
	girl* pgirl = new girl("小娟");
	Proxy* pProxy = new Proxy(new Puisuit(pgirl));
	pProxy->giveDolls();
	pProxy->giveFlowers();
	pProxy->giveChocolate();
	//system("PAUSE");
	getchar();
	return 0;
}