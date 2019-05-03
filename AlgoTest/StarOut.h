#pragma once
#include <string>

using namespace std;

class StarOut
{
public:
	StarOut();
	~StarOut();
	void starOut(string &input);
private:
	bool hasStar(string input);
	void truncate(string &input);

};

