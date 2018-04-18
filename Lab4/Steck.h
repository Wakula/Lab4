#ifndef _STECK_H_
#define _STECK_H_

#include <iostream>
#include <string>
using namespace std;

struct Steck
{
	string data;
	Steck* next;
};
void print(Steck*);
void push(Steck**, string);
int getSize(Steck*);
string getFront(Steck*);
void pop(Steck**);
void clear(Steck**);

#endif
