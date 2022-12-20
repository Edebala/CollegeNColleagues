#pragma once
#include "creature.h"

class Creature;
class Humanoid;

class Slot{
	virtual void use(Humanoid* user, Creature* enemy)=0;
};
