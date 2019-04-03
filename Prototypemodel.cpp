#include <iostream>
#include <string>
using namespace std;

class Prototype
{
public:
	Prototype() :s(""){}
	Prototype(string str) :s(str){}
	void show()
	{
		cout << s << endl;
	}
	virtual Prototype* clone() = 0;
private:
	string s;
};

class ConcreatePrototype1 :public Prototype
{
public:
	ConcreatePrototype1(){}
	ConcreatePrototype1(string s) :Prototype(s){}
	virtual Prototype* clone()
	{
		ConcreatePrototype1* cp1 = new ConcreatePrototype1;
		*cp1 = *this;
		return cp1;
	}
};

class ConcreatePrototype2 :public Prototype
{
public:
	ConcreatePrototype2(){}
	ConcreatePrototype2(string s) :Prototype(s){}
	virtual Prototype* clone()
	{
		ConcreatePrototype2* cp2 = new ConcreatePrototype2;
		*cp2 = *this;
		return cp2;
	}
};

int main(void)
{
	ConcreatePrototype1 cp1("test");
	ConcreatePrototype2* cp2 =(ConcreatePrototype2*)cp1.clone();
	cp1.show();
	cp2->show();

	//system("PAUSE");
	getchar();
	return 0;
}