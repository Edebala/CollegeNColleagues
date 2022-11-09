#include "creature.h"

using namespace std;

class Effect{
    string name;
	int duration;
public:
    Effect(string name, int duration);
	void affect(Creature* target);
}

Effect::Effect(string name, int duration) {
    this->name = name;
    this-> duration = duration;
}


