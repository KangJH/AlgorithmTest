// AlgoTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include "PalindromeChecker.h"
//#include "StringReplacer.h"
//#include "CharRedundantChecker.h"
#include "ArrayAlgo.h"
#include <string>
int main()
{
	string temp;
	while (temp.compare("exit") != 0)
	{
		std::cout << "Put text to check palindrome : ";
		getline(cin, temp);
		if (!temp.empty())
		{
			//PalindromeChecker palindromeChecker(temp);
			//bool ret = palindromeChecker.Check();
			//std::cout << "Palindrome Check result is " << ret << "\n";
			
			//StringReplacer replacer(temp);
			//string newstring = replacer.Replace("ing", "%0");
			//std::cout << "Replacer result is " << newstring << "\n";
			
			//CharRedundantChecker checker(temp);
			//std::cout << "Checker result is " << checker.Check() << "\n";

			std::vector<std::vector<int>> nums = {
				//{ 1, 10, 10, 2 }, { 10, 2, 10 }, {1, 99, 10 }, {10, 13, 10, 14}, {10, 13, 10, 14, 10},
				//{10, 10, 3 }, { 1 }, {13, 1 }, {10}, {}
				{0, 5, 0, 3}, {0, 4, 0, 3}, {0, 1, 0}, {0, 1, 5}, {0, 2, 0}, {0}, {},
				{7, 0, 4, 3, 0, 2}, {7, 0, 4, 3, 0, 1}, {7, 0, 4, 3, 0, 0}, {7, 0, 1, 0, 0, 7}
			};
			ArrayAlgo algo;
			std::vector<std::vector<int>>::iterator itr1 = nums.begin();
			for (; itr1 != nums.end(); itr1++)
			{
				algo.zeroMax(*itr1);
				std::cout << "{";
				std::vector<int>::iterator itr2 = itr1->begin();
				for (; itr2 != itr1->end(); itr2++)
				{
					std::cout << *itr2 << ",";
				}
				std::cout << "}\n";
			}
		}
		else
		{
			std::cout << "Put correct text! Your input: " << temp << "\n";
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
