#include <iostream>
using namespace std;

// 构建器模式
class builder
{
public:
	virtual  void buildengine() = 0;
	virtual  void buildbody() = 0;
	virtual  void buildtires() = 0;
};

class Truckbuild :public builder
{
public:
	virtual void buildengine()
	{
		cout << "Truck engine!" << endl;
	}
	virtual void buildbody()
	{
		cout << "Truck body!" << endl;
	}
	virtual void buildtires()
	{
		cout << "Truck tires!" << endl;
	}
};


class Carbuild :public builder
{
public:
	virtual void buildengine()
	{
		cout << "Car engine!" << endl;
	}
	virtual void buildbody()
	{
		cout << "Car body!" << endl;
	}
	virtual void buildtires()
	{
		cout << "Car tires!" << endl;
	}
};

class Director
{
private:
	builder* m_build;
public:
	Director(builder* build) :m_build(build)
	{

	}
	virtual void create()
	{
		m_build->buildengine();
		m_build->buildbody();
		m_build->buildtires();
	}
};

int main(void)
{
	builder* build_truck = new Truckbuild();
	Director director_truck(build_truck);
	director_truck.create();

	builder* build_car = new Carbuild();
	Director director_car(build_car);
	director_car.create();

	//system("PAUSE");
	getchar();
	return 0;
}