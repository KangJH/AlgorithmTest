#include "pch.h"
#include "ArrayAlgo.h"


ArrayAlgo::ArrayAlgo()
{
}


ArrayAlgo::~ArrayAlgo()
{
}

void ArrayAlgo::withoutTen(vector<int>& nums)
{
	vector<int> newArray = {};
	int countof10 = 0;
	vector<int>::iterator itr = nums.begin();
	for (; itr != nums.end(); itr++)
	{
		if (*itr == 10)
		{
			countof10++;
		}
		else
		{
			newArray.push_back(*itr);
		}
	}
	for (int i = countof10; i > 0; i--)
	{
		newArray.push_back(0);
	}
	nums = newArray;
}

void ArrayAlgo::zeroMax(vector<int>& nums)
{
	vector<int>::iterator itr = nums.begin();
	if (nums.size() > 0)
	{
		for (; itr != nums.end() - 1; itr++)
		{
			if (*itr == 0)
			{
				*itr = findBiggestOddNum(nums, itr + 1);
			}
		}
	}
	
}

int ArrayAlgo::findBiggestOddNum(const vector<int>& nums, const vector<int>::iterator startItr)
{
	int max = 0;
	vector<int>::iterator itr = startItr;

	for (; itr != nums.end(); itr++)
	{
		if ((((*itr) & 0x00000001) == 1) && (*itr > max))
		{
			max = *itr;
		}
	}
	return max;
}
