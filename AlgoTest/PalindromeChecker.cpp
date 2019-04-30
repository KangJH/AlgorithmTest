#include "pch.h"
#include "PalindromeChecker.h"


PalindromeChecker::PalindromeChecker(const string& input)
	: inputText(input)
{
}


PalindromeChecker::~PalindromeChecker()
{
}

bool PalindromeChecker::Check()
{
	bool ret = false;
	int textLength = inputText.length();
	if (textLength % 2 != 0)
	{
		int midIndex = textLength / 2;
		int compareIndex = 1;
		while (compareIndex <= midIndex)
		{
			if (inputText[midIndex - compareIndex] != inputText[midIndex + compareIndex])
			{
				break;
			}
			compareIndex++;
		}
		if (compareIndex > midIndex)
		{
			ret = true;
		}
	}
	return ret;
}