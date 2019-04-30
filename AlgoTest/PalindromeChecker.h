#pragma once
#include <string>

using namespace std;

class PalindromeChecker
{
public:
	PalindromeChecker(const string& input);
	~PalindromeChecker();
	bool Check();
private:
	const string inputText;
};

