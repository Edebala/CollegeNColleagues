#include "creature.h"

using namespace std;

class Creature;

class Effect{
    string name;
	int duration;
public:
    Effect(const string& name, int duration);
	void affect(Creature* target);
};

Effect::Effect(const string& name, int duration) {
    this->name = name;
    this->duration = duration;
}



