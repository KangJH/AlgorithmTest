// AlgoTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include "PalindromeChecker.h"
//#include "StringReplacer.h"
//#include "CharRedundantChecker.h"
#include "ArrayAlgo.h"
#include "StringTest.h"
#include "FileHandleTest.h"
#include "SortTest.h"
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

			ArrayAlgo algo;
			//algo.maxMirror();
			//algo.linkedListTest();
			StringTest strTest;
			//strTest.mergeTwo();
			FileHandleTest filetest;
			//filetest.ReadWrite();
			//filetest.OpenCSV();
			SortTest test;
			test.QuickSort();
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
