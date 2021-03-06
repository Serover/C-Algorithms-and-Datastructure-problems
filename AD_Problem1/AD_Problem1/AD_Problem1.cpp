// AD_Problem1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include "AD_Problem1.h"

using namespace std;

int main()
{
	//ModifiedBucketSort();
	InsertionSort();

	return 0;
}

void InsertionSort()
{
	vector<int> v = { 3,9,5,1,7,9 };
	int temp = 0, j = 0;
	for (int i = 1; i < v.size(); i++)
	{
		temp = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > temp)
		{
			v[j + 1] = v[j];
			j--;
		}

		v[j + 1] = temp;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

void ModifiedBucketSort()
{
	int k = 0;
	vector<int> v = { 3,9,5,1,7,9 };

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > k)
			k = v[i];
	}

	vector<int> w;

	for (int i = 0; i < k + 1; i++)
	{
		w.push_back(0);
	}

	for (int i = 0; i < v.size(); i++)
	{
		w[v[i]] = w[v[i]] + 1;
	}

	for (int i = 0; i < w.size(); i++)
	{
		for (int j = 0; j < w[i]; j++) // This loop is for multiples of same character.
		{
			cout << i << endl;
		}
	}
}