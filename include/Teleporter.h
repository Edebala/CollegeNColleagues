#pragma once
#include "Map.h"
#include "Character.h"

class Teleporter: public Entity{
	int targetX,targetY;
	string targetMapFileName;
public:
	Teleporter(int posX,int posY,int tX,int tY,string map);
	int getTargetX();
	int getTargetY();
};
