/*
 *  main.cpp
 *  stack
 *
 */

#include "DynStack.h"
#include <iostream>

using namespace std;

int main()
{
	int ival;
	double dval;
	char cval;
	DynStack<int> istack;
	DynStack<double> dstack;
	DynStack<char> cstack;

	cout << "Integer stack\n";
	for (int i = 1; i < 12; i+=2)
		istack.push(i);

	istack.pop(ival);
	cout << ival << endl;

	cout << "Double stack\n";
	for (int i = 1; i < 12; i+=2)
		dstack.push(static_cast<double>(i));

	dstack.pop(dval);
	cout << dval << endl;
	
	
	return 0;
}

