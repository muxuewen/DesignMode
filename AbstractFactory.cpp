#include <iostream>
using namespace std;

// ���󹤳�ģʽ
class Iuser
{
public:
	virtual void insert() = 0;
	virtual void getdata() = 0;
};

class SQLServer_Iuser :public Iuser
{
public:
	void insert()
	{
		cout << "SQLServer��usert���в������ݣ�" << endl;
	}

	void getdata()
	{
		cout << "SQLServer��user���л�ȡ���ݣ�" << endl;
	}
};

class Access_Iuser : public Iuser
{
public:
	void insert()
	{
		cout << "Access��usert���в������ݣ�" << endl;
	}

	void getdata()
	{
		cout << "Access��user���л�ȡ���ݣ�" << endl;
	}
};

class IDepartment
{
public:
	virtual void insert() = 0;
	virtual void getdata() = 0;
};

class SQLServer_IDepartment :public IDepartment
{
public:
	void insert()
	{
		cout << "SQLServer��IDepartment���в������ݣ�" << endl;
	}

	void getdata()
	{
		cout << "SQLServer��IDepartment���л�ȡ���ݣ�" << endl;
	}
};

class Access_IDpartment :public IDepartment
{
public:
	void insert()
	{
		cout << "Access��IDepartment���в������ݣ�" << endl;
	}

	void getdata()
	{
		cout << "Access��IDepartment���л�ȡ���ݣ�" << endl;
	}
};

class Factory
{
public:
	virtual Iuser* createIuser() = 0;
	virtual IDepartment* createIDepartment() = 0;
};

class Factory_SQLServer :public Factory
{
public:
	virtual Iuser* createIuser()
	{
		return new SQLServer_Iuser();
	}
	virtual IDepartment* createIDepartment()
	{
		return new SQLServer_IDepartment();
	}
};

class Factory_Access :public Factory
{
public:
	virtual Iuser* createIuser()
	{
		return new Access_Iuser();
	}

	virtual IDepartment* createIDepartment()
	{
		return new Access_IDpartment();
	}
};


int main(void)
{
	Factory* SqlServer = new Factory_SQLServer();
	SqlServer->createIuser()->insert();
	SqlServer->createIuser()->getdata();
	SqlServer->createIDepartment()->insert();
	SqlServer->createIDepartment()->getdata();

	Factory* Access = new Factory_Access();
	Access->createIuser()->insert();
	Access->createIuser()->getdata();
	Access->createIDepartment()->insert();
	Access->createIDepartment()->getdata();

	//system("PAUSE");
	getchar();
	return 0;
}