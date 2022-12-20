#pragma once
#include "Map.h"
#include "creature.h"
#include "Entity.h"

enum DIRECTION{
	DIR_EAST,DIR_WEST,DIR_SOUTH,DIR_NORTH};

class Character:public Entity{
	Creature* creature;
public:
	Character(int x,int y,Creature*);
};
