#include "pch.h"
#include "StringTest.h"
#include <iostream>

StringTest::StringTest()
{
}


StringTest::~StringTest()
{
}


void StringTest::mergeTwo()
{
	vector<vector<string>> a = { 
		{"a", "b", "c"}, {"a", "c", "z"}, {"f", "g", "z"}, {"a", "c", "z"},
		{"a", "b", "c", "z"}, {"a", "c", "z"}, {"a", "c", "z"}, {"a", "c", "z"}, {"x", "y", "z"}
	};
	vector<vector<string>> b = {
		{"b", "f", "z"}, {"c", "f", "z"}, {"c", "f", "g"}, {"a", "c", "z"},
		{"a", "c", "z"}, {"a", "b", "c", "z"}, {"a", "c", "z"}, {"a", "c", "y", "z"}, {"a", "b", "z"}
	};
	vector<int> n = {
		3, 3, 3, 3,
		3, 3, 2, 3, 3
	};
	vector<vector<string>>::iterator itr_a = a.begin();
	vector<vector<string>>::iterator itr_b = b.begin();
	vector<int>::iterator itr_n = n.begin();
	for (; itr_a != a.end() && itr_b != b.end() && itr_n != n.end(); itr_a++, itr_b++, itr_n++)
	{
		vector<string> results = mergeTwo(*itr_a, *itr_b, *itr_n);
		vector<string>::iterator itr_result = results.begin();
		for (; itr_result != results.end(); itr_result++)
		{
			cout << *itr_result << ", ";
		}
		cout << "\n";
	}
}
vector<string> StringTest::mergeTwo(vector<string> a, vector<string> b, int n)
{
	vector<string> ret = {};
	int charSet[127] = { 0, };
	vector<string>::iterator itr = a.begin();
	for (; itr != a.end(); itr++)
	{
		charSet[*(itr)->c_str()] += 1;
	}
	//early return check
	int count = 0;
	for (char ch = 'a'; ch < 'a' + n; ch++)
	{
		if (charSet[ch] > 0)
		{
			count++;
		}
	}
	if (count == n)
	{
		for (char ch = 'a'; ch < 'a' + n; ch++)
		{
			ret.push_back(string(1, ch));
		}
		return ret;
	}

	itr = b.begin();
	for (; itr != b.end(); itr++)
	{
		charSet[*(itr)->c_str()] += 1;
	}
	
	count = n;
	for (char i = 0; i < 127; i++)
	{
		if (charSet[i] > 0 && count-- > 0)
		{
			ret.push_back(string(1, i));
		}
	}
	return ret;
}
