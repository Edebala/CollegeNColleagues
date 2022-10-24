#pragma once
#include "includes.h"

using namespace std;

Interface Area{
	int getWidth();
	int getHeight();
	int getBlock(int x,int y);
	int setBlock(int x,int y);
	string getAreaName();
	string getSourceFileName();
	string setSourceFileName();
	int loadFromFile();
};


