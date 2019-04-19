#include <iostream>
#include <list>
using namespace std;

#define SAFE_DELETE(p) if(p){delete p;p = NULL;}

// 双端队列
class Deque
{
public:
	void push_back(int x)
	{
		cout << "Deque push_back" << endl;
	}
	void push_front(int x)
	{
		cout << "Deque push_front" << endl;
	}
	void pop_back()
	{
		cout << "Deque pop_back" << endl;
	}
	void pop_front()
	{
		cout << "Deque pop_front" << endl;
	}
};

// 顺序队列
class Sequence
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};

// 栈
class Stack:public Sequence
{
public:
	void push(int x)
	{
		m_deque.push_back(x);
	}
	void pop()
	{
		m_deque.pop_front();
	}

private:
	Deque m_deque;
};

// 队列
class Queue:public Sequence
{
public:
	void push(int x)
	{
		m_deque.push_back(x);
	}
	void pop()
	{
		m_deque.pop_back();
	}
private:
	Deque m_deque;
};

int main(void)
{
	Sequence* sq1 = new Stack;
	Sequence* sq2 = new Queue;
	sq1->push(1);
	sq1->pop();

	sq2->push(1);
	sq2->pop();

	SAFE_DELETE(sq1);
	SAFE_DELETE(sq2);
	

	//system("PAUSE");
	getchar();
	return 0;
}