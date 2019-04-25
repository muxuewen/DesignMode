#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 饿汉式
class Esingleton
{
private:
	Esingleton(){}
	~Esingleton(){}

	static Esingleton m_single;
public:
	static Esingleton* getInstance()
	{
		return &m_single;
	}
};

Esingleton Esingleton::m_single; // 即类产生的时候就创建好实例对象，这是一种空间换时间的方式

// 懒汉式
class Lsingleton
{
private:
	Lsingleton(){}
	~Lsingleton(){}

	static Lsingleton* m_single;
public:
	static Lsingleton* getInstance()
	{
		if (m_single == NULL)
		{
			m_single = new Lsingleton();
		}
		return m_single;
	}
private:
	class DeleteSingle
	{
	public:
		DeleteSingle(){}
		~DeleteSingle()
		{
			if (m_single != nullptr)
			{
				delete m_single;
				m_single = NULL;
			}
		}
	};
	static DeleteSingle m_ds;
};

Lsingleton* Lsingleton::m_single = nullptr; // 即在需要的时候，才创建对象，这是一种时间换空间的方式
Lsingleton::DeleteSingle Lsingleton::m_ds; // 自动释放内存 

int main(void)
{
	// 饿汉式
	Esingleton* ct1 = Esingleton::getInstance();
	Esingleton* ct2 = Esingleton::getInstance();
	if (ct1 == ct2)
		cout << "The only instance!" << endl;

	// 懒汉式
	Lsingleton* ct3 = Lsingleton::getInstance();
	Lsingleton* ct4 = Lsingleton::getInstance();
	if (ct3 == ct4)
		cout << "The only instance!" << endl;

	//system("PAUSE");
	getchar();
	return 0;
}