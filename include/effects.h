#pragma once
#include "creature.h"

class Creature;

using namespace std;

class Effect{
    string name;
	int duration;
public:
    Effect(const string& name, int duration);
	void affect(Creature* target);
};
