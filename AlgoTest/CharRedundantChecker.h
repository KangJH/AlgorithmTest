#pragma once

#include <string>

using namespace std;

class CharRedundantChecker
{
public:
	CharRedundantChecker(const string& input);
	~CharRedundantChecker();
	bool Check();
private:
	const string& m_InputStr;
};

