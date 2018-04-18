#ifndef _STACK_H_
#define _Stack_H_

#include <iostream>
#include <string>
using namespace std;

struct Stack
{
	string data;
	Stack* next;
};
void print(Stack*);
void push(Stack**, string);
int getSize(Stack*);
string getFront(Stack*);
void pop(Stack**);
void clear(Stack**);

#endif
