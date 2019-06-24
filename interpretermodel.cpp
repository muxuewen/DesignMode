// 行为型模式：解释器模式
// 四则运算
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <typeinfo.h>
#include <vector>
using namespace std;

// 抽象类表达式
class Expression
{
public:
	// 解析公式和数值，其中var中的key是公式中的参数，value值是具体的数字
	// 如:a = 100;b = 20;c = 40;
	virtual int interpreter(map<string,int>& var) = 0;
	virtual ~Expression(){};
};

// 变量解析器(终结符表达式)
class VarExperssion : public Expression
{
private:
	string key;
public:
	VarExperssion(string key)
	{
		this->key = key;
	};

	// 从map中取出变量的值
	int interpreter(map<string,int>& var)
	{
		return var[key];
	}
	~VarExperssion()
	{
		cout << "~VarExpression()" << endl;
	}
};

// 抽象运算符解析器
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

// 加法解析器
class AddExpression : public SymbolExpression
{
public:
	AddExpression(Expression* left, Expression* right) :SymbolExpression(left, right)
	{

	}

	// 把左右两个表达式的运算结果加起来
	int interpreter(map<string, int>& var)
	{
		return left->interpreter(var) + right->interpreter(var);
	}

	~AddExpression()
	{
		cout << "~AddExperssion()" << endl;
	}
};

// 减法解释器
class SubExperssion : public SymbolExpression
{
public:
	SubExperssion(Expression* left, Expression* right) :SymbolExpression(left, right)
	{

	}
	// 把左右两个表达式的运算结果相减
	int interpreter(map<string, int>& var)
	{
		return left->interpreter(var) - right->interpreter(var);
	}
	~SubExperssion()
	{
		cout << "~SubExperssion()" << endl;
	}
};

// 解析器封装类，这个类根据迪米特法则进行封装，目的是让Client只与直接朋友打交道
class Calculator
{
private:
	Expression* expression;
public:
	// 构造函数，传参并解析表达式，构建语法树
	Calculator(string expStr)
	{
		expression = NULL;

		// 栈 用来暂存中间结果
		stack<Expression*> strExp;

		Expression* left = NULL;
		Expression* right = NULL;

		/*从左到向分析表达式（如:a+b-c)，最终的语法树如下：
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
			case '+':// 加法
				// 1.先从栈中取出左操作数
				left = strExp.top();
				strExp.pop();

				// 2.从表达式中取出+号后面的有操作数，并生成终结符解析对象
				right = new VarExperssion(expStr.substr(++i, 1));

				// 3. 将左右操作数相加，将结果放入栈中
				strExp.push(new AddExpression(left,right));

				break;
			case '-':
				left = strExp.top();
				strExp.pop();

				right = new VarExperssion(expStr.substr(++i, 1));

				strExp.push(new SubExperssion(left,right));

				break;
			default:
				// 如果是变量（终结符）：如a+b+c中的a/b/c
				// 则直接生成对应的变量解析器对象
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
			// 左子树
			deltree(branch->getLeft());

			// 右子树
			deltree(branch->getRight());

			// 结点
			delete expression;
		}
	}

	~Calculator()
	{
		deltree(expression);
		expression = NULL;
	}

	// 开始运算
	int run(map<string, int>& var)
	{
		return (expression == NULL) ? 0 : expression->interpreter(var);
	}


};



int main(void)
{
	string expstr = "a+b-c"; // 为简化处理，这里必须是合法表达式

	map<string, int> var; //  相当于Interperter模式中的Context
	var["a"] = 100;
	var["b"] = 20;
	var["c"] = 40;

	Calculator cal(expstr);

	cout << "运算结果为：" << expstr << "=" << cal.run(var) << endl;

	system("PAUSE");

	return 0;
}

/*
运算结果为：a+b-c = 80
~VarExpression()
~VarExpression()
~AddExpression()
~VarExpression()
~SubExpression()
*/