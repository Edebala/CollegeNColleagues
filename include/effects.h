#pragma once
#include "creature.h"

class Creature;

using namespace std;

class Effect{
protected:
	string name;
	int duration;
public:
	int getDuration();
	Effect(const string& name, int duration);
	virtual int affect(Creature* target);
	virtual void print()=0;
};

class Regeneration:public Effect{
	int value;
public:
	Regeneration(int duration,int value);
	int affect(Creature*);
	void print();
};
