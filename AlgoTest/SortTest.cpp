#include "pch.h"
#include "SortTest.h"
#include <vector>
#include <iostream>
using namespace std;

SortTest::SortTest()
{
}


SortTest::~SortTest()
{
}//0, 0, 1
// 1, 1, 2
// 0, 1, 3
// 
void merge(vector<int>& input, int l, int m, int r)
{
	vector<int> front(input.begin() + l, input.begin() + m + 1);
	vector<int> end = {};
	if (m + 1 < input.size())
	{
		end.assign(input.begin() + m + 1, input.begin() + r + 1);
	}
	vector<int> result = {};
	vector<int>::iterator itr_f = front.begin();
	vector<int>::iterator itr_e = end.begin();
	for (; itr_f != front.end() && itr_e != end.end(); itr_f++, itr_e++)
	{
		if (*itr_f < *itr_e)
		{
			result.push_back(*itr_f);
			result.push_back(*itr_e);
		}
		else
		{
			result.push_back(*itr_e);
			result.push_back(*itr_f);
		}
	}

	for (; itr_f != front.end(); itr_f++)
	{
		result.push_back(*itr_f);
	}

	for (; itr_e != end.end(); itr_e++)
	{
		result.push_back(*itr_e);
	}
	vector<int>::iterator result_itr = result.begin();
	for (vector<int>::iterator itr = input.begin() + l; itr < input.begin() + r + 1; itr++, result_itr++)
	{
		*itr = *result_itr;
	}
}

void mergeSort(vector<int>& input, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(input, l, m);
		mergeSort(input, m+1, r);
		merge(input, l, m, r);
	}
}

void SortTest::MergeSort()
{
	vector<int> testNums = { 0, 8, 19, 3, 3, 5, 1 };
	mergeSort(testNums, 0, testNums.size());
	for (vector<int>::iterator itr = testNums.begin(); itr != testNums.end(); itr++)
	{
		cout << *itr << ",";
	}
	cout << "\n";
}

void SortTest::QuickSort()
{

}
