#pragma once

#include <vector>
#include <string>
#include <list>
using namespace std;

class ArrayAlgo
{
public:
	ArrayAlgo();
	~ArrayAlgo();
	void withoutTen();
	void zeroMax();
	void evenOdd();
	void fizzBuzz();
	void maxMirror();
	void linkedListTest();
private:
	int findBiggestOddNum(const vector<int>& nums, const vector<int>::iterator startItr);
	void printArray(const vector<vector<int>> array);
	void withoutTen(vector<int>& nums);
	void zeroMax(vector<int>& nums);
	void evenOdd(vector<int>& nums);
	vector<string> fizzBuzz(int start, int end);
	int maxMirror(const vector<int>& nums);
	int convertListToInt(list<int> input);
};

