#include <iostream>
using namespace std;
// 工厂模式
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

class factory{
public:
	virtual vehicle* create() = 0;
};

class carfactory :public factory
{
public:
	virtual vehicle* create()
	{
		return new car();
	}
};

class truckfactory :public factory
{
public:
	virtual vehicle* create()
	{
		return new truck();
	}
};

int main(void)
{
	carfactory car;
	car.create()->run();

	truckfactory truck;
	truck.create()->run();


	//system("PAUSE");
	getchar();
	return 0;
}