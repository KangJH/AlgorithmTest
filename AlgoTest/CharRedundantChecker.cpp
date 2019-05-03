#include "pch.h"
#include "CharRedundantChecker.h"


CharRedundantChecker::CharRedundantChecker(const string& input)
	:m_InputStr(input)
{

}


CharRedundantChecker::~CharRedundantChecker()
{
}
bool CharRedundantChecker::Check()
{
	bool ret = false;
	int charSet[128] = { 0, };
	for (unsigned int i = 0; i < m_InputStr.length(); i++)
	{
		charSet[(char)m_InputStr.at(i)]++;
	}
	for (char j = 0; j < 127; j++)
	{
		if (j != ' ')
		{
			if (charSet[j] > 1)
			{
				ret = true;
				break;
			}
		}
	}
	return ret;
}
