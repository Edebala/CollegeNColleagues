#pragma once
#include <string>
#include <vector>

class FightLog{
	vector<string> lines;
	int maxSize;
public:
	FightLog(int);
	vector<string> getLines(int stringLength);
	void addLine(string line);
	int getMaxSize();
};
