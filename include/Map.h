#pragma once
#include "iostream"

class Map{
	int width,height;
	int **blocks;
	string fileName;
public:
	int getWidth();
	int getHeight();
	int getBlock(int x,int y);
	int setBlock(int x,int y);
	int loadFromFile();
	Map(int n,int m,int **blocks);
	Map(string filename);
}

