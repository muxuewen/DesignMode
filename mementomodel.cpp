#include <iostream>
#include <string>
using namespace std;

class Memento;

class Originator
{
public:
	string state;
	Memento* CreateMemo();
	void SetMemo(Memento* memo);
	void show()
	{
		cout << "״̬" << state.c_str() << endl;
	}
};

class Memento
{
public:
	string state;
	Memento(string str)
	{
		state = str;
	}
};

Memento* Originator::CreateMemo()
{
	return new Memento(state);
}

void Originator::SetMemo(Memento* memo)
{
	state = memo->state;
}

class Caretaker
{
public:
	Memento* memo;
};


int main(void)
{
	Originator* ogn = new Originator;
	ogn->state = "on";
	ogn->show();

	Caretaker* ctk = new Caretaker;
	ctk->memo = ogn->CreateMemo();

	ogn->state = "off";
	ogn->show();

	ogn->SetMemo(ctk->memo);
	ogn->show();


	//system("PAUSE");
	getchar();
	return 0;
}