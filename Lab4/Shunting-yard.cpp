#include "Shunting-yard.h"

void apply(Stack** operators, Stack** output)
{
	if (getFront(*operators) == "*")
	{
		int a = stoi(getFront(*output));
		pop(&*output);
		int b = stoi(getFront(*output));
		pop(&*output);
		push(&*output, to_string(b * a));
	}
	else if (getFront(*operators) == "/")
	{
		int a = stoi(getFront(*output));
		pop(&*output);
		int b = stoi(getFront(*output));
		pop(&*output);
		push(&*output, to_string(b / a));
	}
	else if (getFront(*operators) == "+")
	{
		int a = stoi(getFront(*output));
		pop(&*output);
		int b = stoi(getFront(*output));
		pop(&*output);
		push(&*output, to_string(b + a));
	}
	else if (getFront(*operators) == "-")
	{
		int a = stoi(getFront(*output));
		pop(&*output);
		int b = stoi(getFront(*output));
		pop(&*output);
		push(&*output, to_string(b - a));
	}
	else if (getFront(*operators) == "^")
	{
		int a = stoi(getFront(*output));
		pop(&*output);
		int b = stoi(getFront(*output));
		pop(&*output);
		push(&*output, to_string(pow(b, a)));
	}
	pop(&*operators);
}
void calc()
{
	Stack* operators = nullptr;
	Stack* output = nullptr;
	string expr;
	cout << "Enter ur expression: ";
	cin >> expr;
	cout << endl;
	int i = 0;
	while (expr[i] != '\0')
	{
		if (expr[i] >= '0' && expr[i] <= '9')
		{
			string num = "";
			while (expr[i] >= '0' && expr[i] <= '9')
			{
				num += expr[i];
				i++;
			}
			push(&output, num);
			i--;
		}
		else if (expr[i] == '*' || expr[i] == '/')
		{
			while (operators != nullptr && (getFront(operators) == "*" || getFront(operators) == "/" || getFront(operators) == "^"))
			{
				apply(&operators, &output);
			}
			string oper = "";
			oper += expr[i];
			push(&operators, oper);
		}
		else if (expr[i] == '+' || expr[i] == '-')
		{
			while (operators != nullptr && getFront(operators) != "(")
			{
				apply(&operators, &output);
			}
			string oper = "";
			oper += expr[i];
			push(&operators, oper);
		}
		else if (expr[i] == '^')
		{
			push(&operators, "^");
		}
		else if (expr[i] == '(')
		{
			push(&operators, "(");
		}
		else if (expr[i] == ')')
		{
			while (getFront(operators) != "(")
			{
				apply(&operators, &output);
			}
			pop(&operators);
		}
		i++;
	}
	while (operators != nullptr)
	{
		apply(&operators, &output);
	}
	cout << "Result: ";
	print(output);
}