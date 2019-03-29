#include <iostream>
using namespace std;

class cake
{
public:
	virtual ~cake(){};
	virtual void showcake() = 0;
	string name;
};

class Concrete :public cake
{
public:
	Concrete()
	{
		name = "ԭʼ����";
	}
	virtual ~Concrete(){};
	void showcake()
	{
		cout << name.c_str() << endl;
	}
};


class Dercater :public cake
{
protected:
	cake* Cake;
public:
	virtual void showcake() = 0;
	virtual ~Dercater(){};
};

class DercaterMilk :public Dercater
{
public:
	DercaterMilk(cake* Cake)
	{
		this->Cake = Cake;
	}
	virtual void showcake()
	{
		this->name = Cake->name + "������";
		cout << this->name.c_str() << endl;
	}
	virtual ~DercaterMilk(){};
};

class DercaterCholate :public Dercater
{
public:
	DercaterCholate(cake* pCake)
	{
		this->Cake = pCake;
	}
	virtual void showcake()
	{
		this->name = Cake->name + "���ɿ���";
		cout << this->name.c_str() << endl;
	}
 	virtual ~DercaterCholate(){};
};

int main(void)
{
	Concrete* con = new Concrete();
	con->showcake();

	DercaterMilk* milk = new DercaterMilk(con);
	milk->showcake();

	DercaterCholate* cho = new DercaterCholate(milk);
	cho->showcake();

	delete con;
	delete milk;
	delete cho;

	//system("PAUSE");
	getchar();
	return 0;
}