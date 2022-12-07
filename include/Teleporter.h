#pragma once
#include "Map.h"
#include "Character.h"

class Teleporter{
	int posX,posY,targetX,targetY;
	string targetMapFileName;
public:
	Teleporter(int posX,int posY,int tX,int tY,string map);
	int getPosX();
	int getPosY();
	int getTargetX();
	int getTargetY();
};
