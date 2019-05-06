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
	vector<int> end(input.begin() + m + 1, input.begin() + r + 1);
	vector<int>::iterator result = input.begin() + l;
	vector<int>::iterator itr_f = front.begin();
	vector<int>::iterator itr_e = end.begin();
	for (; itr_f != front.end() && itr_e != end.end(); )
	{
		if (*itr_f < *itr_e)
		{
			*result = *itr_f;
			itr_f++;
		}
		else
		{
			*result = *itr_e;
			itr_e++;
		}
		result++;
	}

	for (; itr_f != front.end(); itr_f++)
	{
		*result = *itr_f;
		result++;
	}

	for (; itr_e != end.end(); itr_e++)
	{
		*result = *itr_e;
		result++;
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
	vector<vector<int>> testNums = {
		{ 0, 8, 19, 3, 3, 5, 1 } , {}, {1}, 
		{23, 5234, 523, 64, -1, 3, 4}, 
		{0,0,0,0,0,0,1},
		{1,3,4,6,6,3,2,76,9,4,2,5,6,4,2,6,89,}
	};
	for (vector<vector<int>>::iterator itr = testNums.begin(); itr != testNums.end(); itr++)
	{
		vector<int> &val = *itr;
		mergeSort(val, 0, val.size() - 1);
		cout << "{";
		for (vector<int>::iterator itr2 = val.begin(); itr2 != val.end(); itr2++)
		{
			cout << *itr2 << ",";
		}
		cout << "} \n";
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
#include <algorithm>

int partitionArray(vector<int>& a, int l, int r)
{
	//Select Pivot
	int pivotVal = 0;
	int m = (l + r) / 2;
	if (a[l] < a[r])
	{
		if (a[r] < a[m])
		{
			pivotVal = a[r];
		}
		else
		{
			if (a[l] < a[m])
				pivotVal = a[m];
			else
				pivotVal = a[l];
		}
	}
	else
	{
		if (a[l] < a[m])
		{
			if (a[r] < a[m])
				pivotVal = a[r];
			else
				pivotVal = a[m];
		}
		else
		{
			pivotVal = a[l];
		}
	}
	int leftIndex = l;
	int rightIndex = r;

	while (leftIndex != rightIndex)
	{
		if (a[leftIndex] <= pivotVal)
		{
			leftIndex++;
		}
		else
		{
			while (a[rightIndex] > pivotVal)
			{
				if (rightIndex == leftIndex)
				{
					break;
				}
				rightIndex--;
			}
			swap(a[leftIndex], a[rightIndex]);
		}
	}
	return leftIndex;
}

void quickSort(vector<int>& a, int l, int r)
{
	if (l < r)
	{
		int p = partitionArray(a, l, r);
		quickSort(a, l, p - 1);
		quickSort(a, p, r);
	}
}

void SortTest::QuickSort()
{
	vector<vector<int>> testNums = {
		// 0, 8, 19, 3, 3, 5, 1 } , {}, {1},
		//{23, 5234, 523, 64, -1, 3, 4},
		//{0,0,0,0,0,0,1},
		{1,3,4,6,6,3,2,76,9,4,2,5,6,4,2,6,89,}
	};
	for (vector<vector<int>>::iterator itr = testNums.begin(); itr != testNums.end(); itr++)
	{
		vector<int> &val = *itr;
		quickSort(val, 0, val.size() - 1);
		cout << "{";
		for (vector<int>::iterator itr2 = val.begin(); itr2 != val.end(); itr2++)
		{
			cout << *itr2 << ",";
		}
		cout << "} \n";
	}
}
