#pragma once
#include <string>
#include <vector>

using namespace std;

class StringTest
{
public:
	StringTest();
	~StringTest();
	void mergeTwo();
private:
	vector<string> mergeTwo(vector<string> a, vector<string> b, int n);
};

