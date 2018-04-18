#include "Stack.h"

using namespace std;

void print(Stack* s)
{
	if (s == nullptr)
	{
		cout << endl;
		return;
	}
	cout << s->data << " ";
	print(s->next);
}

void push(Stack** s, string data)
{
	Stack* tmp = new Stack;
	tmp->data = data;
	tmp->next = *s;
	*s = tmp;
}

int getSize(Stack* s)
{
	static int sz = 0;
	if (s == nullptr) return sz;
	sz++;
	getSize(s->next);
}

string getFront(Stack* s)
{
	if (s == nullptr) return '\0';
	return s->data;
}

void pop(Stack** s)
{
	if (*s == nullptr) return;
	Stack* tmp = (*s)->next;
	delete (*s);
	(*s) = tmp;
}

void clear(Stack** s)
{
	if (*s == nullptr) return;
	while (*s != nullptr) pop(s);
}