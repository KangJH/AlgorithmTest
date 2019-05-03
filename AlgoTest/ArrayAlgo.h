#pragma once

#include <vector>

using namespace std;

class ArrayAlgo
{
public:
	ArrayAlgo();
	~ArrayAlgo();
	void withoutTen(vector<int>& nums);
	void zeroMax(vector<int>& nums);
private:
	int findBiggestOddNum(const vector<int>& nums, const vector<int>::iterator startItr);

};

