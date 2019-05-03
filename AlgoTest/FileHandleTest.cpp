#include "pch.h"
#include "FileHandleTest.h"

#include <iostream>
#include <fstream>
#include <sstream>

FileHandleTest::FileHandleTest()
{
}


FileHandleTest::~FileHandleTest()
{
}

void FileHandleTest::ReadWrite()
{
	const char* filename = "C:\\Users\\lukekang\\Desktop\\temp.txt";
	const char* filename2 = "C:\\Users\\lukekang\\Desktop\\temp2.txt";
	ifstream inFile(filename);
	ofstream outFile(filename2, ios::app);
	string line;
	while (!inFile.eof())
	{
		getline(inFile, line);
		line += "\n";
		outFile.write(line.c_str(), line.length());
		cout << line;
	}
	inFile.close();
	outFile.close();

}
vector<vector<string>> FileHandleTest::OpenCSV()
{
	vector<vector<string>> ret = {};
	const char* filename = "C:\\Users\\lukekang\\Desktop\\Question list for feedback workshop in Korea - Sheet1.csv";
	ifstream inFile(filename);
	while (!inFile.eof())
	{
		string line;
		getline(inFile, line);
		stringstream ss(line);
		string word;
		vector<string> row;
		while (getline(ss, word, ','))
		{
			row.push_back(word);
		}
		ret.push_back(row);
	}
	return ret;
}
