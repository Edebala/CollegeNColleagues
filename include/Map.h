#pragma once
#include <vector>
#include <fstream>

class Entity;

using namespace std;

class Map{
	int width,height;
	int **blocks;
	string fileName;
public:
	int getWidth();
	int getHeight();
	int getBlock(int x,int y);
	int setBlock(int x,int y,int block);
	int loadFromFile(string file);
	Map(int n,int m,int **blocks);
	Map(string filename);
	Map* getSubMap(int x,int y, int m,int n);
	void printMap(vector <Entity*>);
};

