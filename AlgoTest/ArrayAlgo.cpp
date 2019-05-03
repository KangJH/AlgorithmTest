#include "pch.h"
#include "ArrayAlgo.h"
#include <iostream>
#include <deque>

ArrayAlgo::ArrayAlgo()
{
}


ArrayAlgo::~ArrayAlgo()
{
}
void ArrayAlgo::withoutTen()
{
	std::vector<std::vector<int>> nums = {
		{ 1, 10, 10, 2 }, { 10, 2, 10 }, {1, 99, 10 }, {10, 13, 10, 14}, {10, 13, 10, 14, 10},
		{10, 10, 3 }, { 1 }, {13, 1 }, {10}, {}
	};
	std::vector<std::vector<int>>::iterator itr1 = nums.begin();
	for (; itr1 != nums.end(); itr1++)
	{
		withoutTen(*itr1);
	}
	printArray(nums);
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

void ArrayAlgo::zeroMax()
{
	std::vector<std::vector<int>> nums = {
		{0, 5, 0, 3}, {0, 4, 0, 3}, {0, 1, 0}, {0, 1, 5}, {0, 2, 0}, {1}, {0}, {},
		{7, 0, 4, 3, 0, 2}, {7, 0, 4, 3, 0, 1}, {7, 0, 4, 3, 0, 0}, {7, 0, 1, 0, 0, 7}
	};
	std::vector<std::vector<int>>::iterator itr1 = nums.begin();
	for (; itr1 != nums.end(); itr1++)
	{
		zeroMax(*itr1);
	}
	printArray(nums);
}

void ArrayAlgo::zeroMax(vector<int>& nums)
{
	if (nums.size() > 0)
	{
		int maxOdd = 0;
		vector<int>::reverse_iterator itr(nums.rbegin());
		for (; itr != nums.rend(); itr++)
		{
			if ((((*itr) & 0x00000001) == 1) && (*itr > maxOdd))
			{
				maxOdd = *itr;
			}
			else if (*itr == 0)
			{
				*itr = maxOdd;
			}
		}
	}
	
}
void ArrayAlgo::evenOdd()
{
	std::vector<std::vector<int>> nums = {
		{1, 0, 1, 0, 0, 1, 1}, {3, 3, 2}, {2, 2, 2}, {3, 2, 2}, {1, 1, 0, 1, 0}, {1}, {},
		{1,2}, {2,1}
	};
	std::vector<std::vector<int>>::iterator itr1 = nums.begin();
	for (; itr1 != nums.end(); itr1++)
	{
		evenOdd(*itr1);
	}
	printArray(nums);
}

void ArrayAlgo::evenOdd(vector<int>& nums)
{
	deque<int> myQ = {};
	vector<int>::iterator itr = nums.begin();
	for (; itr != nums.end(); itr++)
	{
		if (((*itr) & 0x00000001) == 1)
		{
			// ODD
			myQ.push_back(*itr);
		}
		else
		{
			// EVEN
			myQ.push_front(*itr);
		}
	}
	nums.clear();
	nums.assign(myQ.begin(), myQ.end());
	
}

void ArrayAlgo::fizzBuzz()
{
	std::vector<std::vector<int>> nums = {
		{1, 10}, {3, 100}, {5, 8} 
	};
	std::vector<std::vector<int>>::iterator itr1 = nums.begin();
	for (; itr1 != nums.end(); itr1++)
	{
		std::cout << "{";
		vector<string> result = fizzBuzz((*itr1)[0], (*itr1)[1]);
		for (vector<string>::iterator itr = result.begin(); itr != result.end(); itr++)
		{
			cout << *itr << ", ";
		}
		std::cout << "}\n";
	}
}

vector<string> ArrayAlgo::fizzBuzz(int start, int end)
{
	char buffer10[10];
	vector<string> ret = {};
	for (int i = start; i < end; i++)
	{
		bool isMultipleby3 = (i % 3 == 0);
		bool isMultipleby5 = (i % 5 == 0);
		if (isMultipleby3 || isMultipleby5)
		{
			string fizzbuzz = "";
			if (isMultipleby3)
			{
				fizzbuzz = "Fizz";
			}
			if (isMultipleby5)
			{
				fizzbuzz += "Buzz";
			}
			ret.push_back(fizzbuzz);
		}
		else
		{
			_itoa_s(i, buffer10, 10);
			ret.push_back(string(buffer10));
		}
	}
	return ret;
}
void ArrayAlgo::maxMirror()
{
	std::vector<std::vector<int>> nums = {
		//{1, 2, 3, 8, 9, 3, 2, 1}, {1, 2, 1, 4}, {7, 1, 2, 9, 7, 2, 1},
		//{21, 22, 9, 8, 7, 6, 23, 24, 6, 7, 8, 9, 25, 7, 8, 9}, 
		//{1, 2, 1, 20, 21, 1, 2, 1, 2, 23, 24, 2, 1, 2, 1, 25},
		{1, 2, 3, 2, 1}, {1, 2, 3, 3, 8},
		{1, 2, 7, 8, 1, 7, 2}, {1,1,1}, {1}, {}, {9, 1, 1, 4, 2, 1, 1, 1}, {5, 9, 9, 4, 5, 4, 9, 9, 2}, {5, 9, 9, 6, 5, 4, 9, 9, 2},
		{5, 9, 1, 6, 5, 4, 1, 9, 5}
	};
	std::vector<std::vector<int>>::iterator itr1 = nums.begin();
	for (; itr1 != nums.end(); itr1++)
	{
		int result = maxMirror(*itr1);
		cout << result << "\n";
	}
}

int ArrayAlgo::maxMirror(const vector<int>& nums)
{
	int ret = 0;
	if (nums.size() < 2)
	{
		ret = nums.size();
	}
	else
	{
		int seriesCount = 0;
		int maxSeriesCount = 0;
		vector<int>::const_iterator itr = nums.begin();
		for (; itr != nums.end(); itr++)
		{
			vector<int>::const_iterator temp_itr = itr;
			for (vector<int>::const_reverse_iterator backward_itr = nums.rbegin(); backward_itr.base() >= temp_itr; backward_itr++)
			{
				if (*temp_itr == *backward_itr)
				{
					seriesCount++;
					if (temp_itr != nums.end() - 1)
					{
						temp_itr++;
					}
				}
				else
				{
					if (seriesCount > maxSeriesCount)
					{
						maxSeriesCount = seriesCount;
					}
					temp_itr = itr;
					seriesCount = 0;
				}
			}
			if (seriesCount > maxSeriesCount)
			{
				maxSeriesCount = seriesCount;
			}
			seriesCount = 0;
		}
		ret = maxSeriesCount;
	}
	return ret;
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
int ArrayAlgo::convertListToInt(list<int> input)
{
	int ret = 0, digit = 0, fontDigit = 1;
	for (list<int>::iterator itr = input.begin(); itr != input.end(); itr++)
	{
		for (int i = 0; i < digit; i++)
		{
			fontDigit *= 10;
		}
		ret += (fontDigit * *(itr));
		digit++;
		fontDigit = 1;
	}
	return ret;
}
void ArrayAlgo::linkedListTest()
{
	list<int> a = { 7, 1, 6 };
	list<int> b = { 5, 9, 2 };
	int numA = convertListToInt(a);
	int numB = convertListToInt(b);
	int result = numA + numB;
	cout << "Result : " << result;
	char buffer[10] = { 0, };
	_itoa_s(result, buffer, 10);
	string resultStr = string(buffer);
	list<int> resultList = {};
	for (size_t i = 0; i < resultStr.length(); i++)
	{
		const char num = resultStr.at(i);
		resultList.push_front(atoi(&num));
	}

}

void ArrayAlgo::printArray(const vector<vector<int>> array)
{
	vector<vector<int>>::const_iterator itr1 = array.begin();
	for (; itr1 != array.end(); itr1++)
	{
		std::cout << "{";
		std::vector<int>::const_iterator itr2 = itr1->begin();
		for (; itr2 != itr1->end(); itr2++)
		{
			std::cout << *itr2 << ",";
		}
		std::cout << "}\n";
	}
}
