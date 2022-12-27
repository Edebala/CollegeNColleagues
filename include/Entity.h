#pragma once
#include <vector>

class Map;

using namespace std;

class Entity{
protected:
	int posX,posY;
	vector<int> walkableBlocks;

	void move(int x,int y);
public:
	Entity(int, int);
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	vector<int>getWalkableBlocks();
	bool canWalkOn(int);
	int tryToMove(int x,int y,Map* map);
};

