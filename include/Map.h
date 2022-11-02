#pragma once

class Map{
	int size[2];
	int **blocks;
public:
	int *getSize();
	int *getSize(blocks);
	int getBlock(int x,int y);
	Map(int n,int m,int **blocks);
	Map(string filename);
}

