#pragma once
#include <vector>
#include <string>

using namespace std;

class FileHandleTest
{
public:
	FileHandleTest();
	~FileHandleTest();
	void ReadWrite();
	vector<vector<string>> OpenCSV();
};

