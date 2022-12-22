#pragma once
#include <string>

class Creature;
class Humanoid;

class Slot{
	string name;
public:
	string getName();
	virtual bool isSpell()=0;
	void setName(string name);
	Slot(string);
	virtual int use(Humanoid* user, Creature* enemy)=0;
};
