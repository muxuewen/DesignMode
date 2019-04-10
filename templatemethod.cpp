#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	void Show()
	{
		cout << test() << endl;
	}
protected:
	virtual string test() = 0;
};

class A1 :public A
{
protected:
	string test()
	{
		return "A1";
	}
};

class A2 :public A
{
protected:
	string test()
	{
		return "A2";
	}
};

int main(void)
{
	A* a = new A1;
	a->Show();

	A* b = new A2;
	b->Show();

	//system("PAUSE");
	getchar();
	return 0;
}