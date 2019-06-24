// ��Ϊ��ģʽ��������ģʽ
// ��������
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <typeinfo.h>
#include <vector>
using namespace std;

// ��������ʽ
class Expression
{
public:
	// ������ʽ����ֵ������var�е�key�ǹ�ʽ�еĲ�����valueֵ�Ǿ��������
	// ��:a = 100;b = 20;c = 40;
	virtual int interpreter(map<string,int>& var) = 0;
	virtual ~Expression(){};
};

// ����������(�ս�����ʽ)
class VarExperssion : public Expression
{
private:
	string key;
public:
	VarExperssion(string key)
	{
		this->key = key;
	};

	// ��map��ȡ��������ֵ
	int interpreter(map<string,int>& var)
	{
		return var[key];
	}
	~VarExperssion()
	{
		cout << "~VarExpression()" << endl;
	}
};

// ���������������
class SymbolExpression : public Expression
{
protected:
	Expression* left;
	Expression* right;
public:
	SymbolExpression(Expression* left, Expression* right)
	{
		this->left = left;
		this->right = right;
	}

	Expression* getLeft()
	{
		return left;
	}

	Expression* getRight()
	{
		return right;
	}
};

// �ӷ�������
class AddExpression : public SymbolExpression
{
public:
	AddExpression(Expression* left, Expression* right) :SymbolExpression(left, right)
	{

	}

	// �������������ʽ��������������
	int interpreter(map<string, int>& var)
	{
		return left->interpreter(var) + right->interpreter(var);
	}

	~AddExpression()
	{
		cout << "~AddExperssion()" << endl;
	}
};

// ����������
class SubExperssion : public SymbolExpression
{
public:
	SubExperssion(Expression* left, Expression* right) :SymbolExpression(left, right)
	{

	}
	// �������������ʽ�����������
	int interpreter(map<string, int>& var)
	{
		return left->interpreter(var) - right->interpreter(var);
	}
	~SubExperssion()
	{
		cout << "~SubExperssion()" << endl;
	}
};

// ��������װ�࣬�������ݵ����ط�����з�װ��Ŀ������Clientֻ��ֱ�����Ѵ򽻵�
class Calculator
{
private:
	Expression* expression;
public:
	// ���캯�������β��������ʽ�������﷨��
	Calculator(string expStr)
	{
		expression = NULL;

		// ջ �����ݴ��м���
		stack<Expression*> strExp;

		Expression* left = NULL;
		Expression* right = NULL;

		/*������������ʽ����:a+b-c)�����յ��﷨�����£�
		*           -
		*         /   \
		*       +     c
		*     /   \
		*    a     b
		*/
		for (unsigned int i = 0; i < expStr.length(); ++i)
		{
			switch (expStr[i])
			{
			case '+':// �ӷ�
				// 1.�ȴ�ջ��ȡ���������
				left = strExp.top();
				strExp.pop();

				// 2.�ӱ��ʽ��ȡ��+�ź�����в��������������ս����������
				right = new VarExperssion(expStr.substr(++i, 1));

				// 3. �����Ҳ�������ӣ����������ջ��
				strExp.push(new AddExpression(left,right));

				break;
			case '-':
				left = strExp.top();
				strExp.pop();

				right = new VarExperssion(expStr.substr(++i, 1));

				strExp.push(new SubExperssion(left,right));

				break;
			default:
				// ����Ǳ������ս��������a+b+c�е�a/b/c
				// ��ֱ�����ɶ�Ӧ�ı�������������
				strExp.push(new VarExperssion(expStr.substr(i,1)));
			}
		}
		if (!strExp.empty())
		{
			expression = strExp.top();
			strExp.pop();
		}

	}

	void deltree(Expression* expression)
	{
		SymbolExpression* branch = dynamic_cast<SymbolExpression*>(expression);
		if (branch == NULL)
			delete branch;
		else
		{
			// ������
			deltree(branch->getLeft());

			// ������
			deltree(branch->getRight());

			// ���
			delete expression;
		}
	}

	~Calculator()
	{
		deltree(expression);
		expression = NULL;
	}

	// ��ʼ����
	int run(map<string, int>& var)
	{
		return (expression == NULL) ? 0 : expression->interpreter(var);
	}


};



int main(void)
{
	string expstr = "a+b-c"; // Ϊ�򻯴�����������ǺϷ����ʽ

	map<string, int> var; //  �൱��Interperterģʽ�е�Context
	var["a"] = 100;
	var["b"] = 20;
	var["c"] = 40;

	Calculator cal(expstr);

	cout << "������Ϊ��" << expstr << "=" << cal.run(var) << endl;

	system("PAUSE");

	return 0;
}

/*
������Ϊ��a+b-c = 80
~VarExpression()
~VarExpression()
~AddExpression()
~VarExpression()
~SubExpression()
*/