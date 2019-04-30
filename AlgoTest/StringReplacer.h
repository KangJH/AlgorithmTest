#pragma once
#include <string>

using namespace std;
class StringReplacer
{
public:
	StringReplacer(const string& inputText);
	~StringReplacer();
	string Replace(const string& old_ch, const string& new_ch);
private:
	const string inputText;
};

