#include <iostream>
using namespace std;

// 接口类
class vehicle{
public:
	virtual void run() = 0;
};

class car :public vehicle
{
public:
	virtual void run()
	{
		cout << "car run!" << endl;
	}
};

class truck :public vehicle
{
public:
	virtual void run()
	{
		cout << "truck run!" << endl;
	}
};

enum type
{
	CAR,
	TRUCK
};

class function
{
public:
	vehicle* create(type name)
	{
		switch (name)
		{
		case CAR:
			return new car();
			break;
		case TRUCK:
			return new truck();
			break;
		default:
			break;
		}
	}
};

int main(void)
{
	function func;
	func.create(CAR)->run();
	func.create(TRUCK)->run();
	system("PAUSE");
	return 0;
}
