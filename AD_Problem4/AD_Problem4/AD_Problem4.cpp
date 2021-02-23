#include "pch.h"
#include <iostream>
#include "AD_Problem4.h"
#include <math.h>
#include <vector>

using namespace std;

int counter = 0;
const int testValue = 3;

int main()
{
	cout << "T_1: " << T_1(testValue) << endl;
	cout << "Counter: " << counter << endl;
	cout << endl;

	counter = 0;

	cout << "T_2: " << T_2(testValue) << endl;
	cout << "Counter: " << counter << endl;
}

int T_1(int n)
{
	counter++;

	if (n == 1)
		return 1;

	double temp = n;
	temp = ceil(temp / 2);

	return T_1(n - 1) + T_1(temp) + n;
}


#ifndef NULL
#define NULL 0
#endif
struct Table
{
	int values[testValue];

	int get(int index)
	{
		int temp = values[index];

		if (temp != NULL)
			return temp;
		else
			return NULL;
	}

	void set(int value, int index)
	{
		values[index] = value;
	}
};

Table t;

int T_2(int n)
{
	counter++;

	if (n == 1)
		return 1;

	double temp = n;
	temp = ceil(temp / 2);

	if (t.get(n) != NULL)
	{
		return t.get(n);
	}
	else
	{
		t.set(T_2(n-1) + T_2(temp) + n, n);
		return t.get(n);
	}
	return NULL;
}
