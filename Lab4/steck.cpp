#include "Steck.h"

using namespace std;

void print(Steck* s)
{
	if (s == nullptr)
	{
		cout << endl;
		return;
	}
	cout << s->data << " ";
	print(s->next);
}

void push(Steck** s, string data)
{
	Steck* tmp = new Steck;
	tmp->data = data;
	tmp->next = *s;
	*s = tmp;
}

int getSize(Steck* s)
{
	static int sz = 0;
	if (s == nullptr) return sz;
	sz++;
	getSize(s->next);
}

string getFront(Steck* s)
{
	if (s == nullptr) return '\0';
	return s->data;
}

void pop(Steck** s)
{
	if (*s == nullptr) return;
	Steck* tmp = (*s)->next;
	delete (*s);
	(*s) = tmp;
}

void clear(Steck** s)
{
	if (*s == nullptr) return;
	while (*s != nullptr) pop(s);
}