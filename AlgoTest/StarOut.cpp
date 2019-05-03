#include "pch.h"
#include "StarOut.h"


StarOut::StarOut()
{
}


StarOut::~StarOut()
{
}

void StarOut::starOut(string &input)
{
	int length = input.length();
	if (length > 2)
	{
		while (hasStar(input))
		{
			truncate(input);
		}
	}
}

bool StarOut::hasStar(string input)
{
	bool ret = false;
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		if (input.substr(i, 1).compare("*") == 0)
		{
			ret = true;
			break;
		}
	}
	return ret;
}

void StarOut::truncate(string &input)
{
	int length = input.length();
	int truncatStart = -1;
	int truncatEnd = -1;
	string prevChar = "";
	for (int i = 0; i < length; i++)
	{
		if ( input.substr(i, 1).compare("*") == 0 )
		{
			if (truncatStart == -1)
			{
				if (i >= 1)
				{
					truncatStart = i - 1;
				}
				else
				{
					truncatStart = 0;
				}
			}
		}
		else
		{
			if (prevChar.compare("*") == 0)
			{
				if (i + 1 < length)
				{
					truncatEnd = i + 1;
				}
				else
				{
					truncatEnd = length - 1;
				}
				string front = input.substr(0, truncatStart);
				string last = input.substr(truncatEnd, length - truncatEnd);
				input = front + last;
				break;
			}
		}
		prevChar = input.substr(i, 1);
	}
}
