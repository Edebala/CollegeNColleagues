#pragma once
#include <string>

class Creature;
class Humanoid;

class Slot{
	virtual int use(Humanoid* user, Creature* enemy)=0;
};
