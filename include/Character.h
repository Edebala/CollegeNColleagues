#pragma once
#include "Map.h"
#include "creatures.h"

enum DIRECTION(DIR_EAST,DIR_WEST,DIR_SOUTH,DIR_NORTH);

class Character{
	int posX,posY;
	Creature* creature;
public:
	int getPosX();
	int getPosY();
	int move(int x,int y);
	int walk(DIRECTION dir);
};
