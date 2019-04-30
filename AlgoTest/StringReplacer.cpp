#include "pch.h"
#include "StringReplacer.h"
#include <algorithm>
#include <vector>

StringReplacer::StringReplacer(const string& input)
	:inputText(input)
{
}


StringReplacer::~StringReplacer()
{
}

string StringReplacer::Replace(const string& old_str, const string& new_str)
{
	string ret;
	vector<string> stringlist;
	unsigned int copyStart = 0, copyEnd = 0;
	unsigned int compare_length = old_str.length();
	while (copyEnd + compare_length <= inputText.length())
	{
		if (inputText.compare(copyEnd, compare_length, old_str, 0, compare_length) == 0)
		{
			stringlist.push_back(inputText.substr(copyStart, copyEnd - copyStart));
			copyStart = copyEnd + compare_length;
			copyEnd = copyStart;
		}
		copyEnd++;
	}

	vector<string>::iterator itr = stringlist.begin();
	while (itr != stringlist.end())
	{
		ret = ret + *itr + new_str;
		itr++;
	}
	if (copyStart < inputText.length())
	{
		ret += inputText.substr(copyStart, inputText.length() - copyStart);
	}
	//std::replace(ret.begin(), ret.end(), old_str, new_str);
	return ret;
}
