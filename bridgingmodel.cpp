#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define SAFE_DELETE(p) if(p){delete p;p = NULL;}

// 软件接口类
class software
{
public:
	virtual void run() = 0;
};


// 微信
class Wechat :public software
{
public:
	virtual void run()
	{
		cout << "running Wechat" << endl;
	}
};

// 钉钉
class DingDing : public software
{
public:
	virtual void run()
	{
		cout << "running DingDing" << endl;
	}
};

// 手机接口类
class Phone
{
public:
	void SetPhone(software* sfw)
	{
		m_software = sfw;
	}
	virtual void run() = 0;
protected:
	software* m_software;
};

// 安卓手机
class Android :public Phone
{
public:
	virtual void run()
	{
		cout << "Android OS ";
		m_software->run();
	}
};

// ios手机
class Ios :public Phone
{
public:
	virtual void run()
	{
		cout << "ios OS ";
		m_software->run();
	}
};

int main(void)
{
	Phone* pPhone;
	pPhone = new Android();
	pPhone->SetPhone(new DingDing());
	pPhone->run();

	pPhone->SetPhone(new Wechat());
	pPhone->run();

	Phone* pPhone1 = new Ios();
	pPhone1->SetPhone(new Wechat());
	pPhone1->run();

	pPhone1->SetPhone(new DingDing());
	pPhone1->run();

	SAFE_DELETE(pPhone);
	SAFE_DELETE(pPhone1);
 

	//system("PAUSE");
	getchar();
	return 0;
}