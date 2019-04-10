#include <iostream>
#include <string>
using namespace std;

class SubSysOne
{
public:
	void MethodOne()
	{
		cout << "MethodOne" << endl;
	}
};

class SubSysTwo
{
public:
	void MethodTwo()
	{
		cout << "MethodTwo" << endl;
	}
};

class SubSysThree
{
public:
	void MethodThree()
	{
		cout << "MethodThree" << endl;
	}
};

class Facade
{
public:
	Facade()
	{
		sub1 = new SubSysOne;
		sub2 = new SubSysTwo;
		sub3 = new SubSysThree;
	}
	~Facade()
	{
		delete sub1;
		delete sub2;
		delete sub3;
	}
	void FacadeMethod()
	{
		sub1->MethodOne();
		sub2->MethodTwo();
		sub3->MethodThree();
	}

private:
	SubSysOne* sub1;
	SubSysTwo* sub2;
	SubSysThree* sub3;
};

int main(void)
{
	Facade* test = new Facade;
	test->FacadeMethod();

	//system("PAUSE");
	getchar();
	return 0;
}