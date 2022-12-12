#pragma once
#include "creature.h"

class Creature;
class Humanoid;

class Spell{
    int duration;
public:
    Spell(int duration);
    void setDuration(int duration);
    int getDuration() const;
		virtual int Cast(Humanoid *caster, Creature* enemy) = 0;
};

class Fireball: public Spell{
public:
		Fireball();
    int Cast(Humanoid *caster, Creature* enemy);
};

class PoisonGas: public Spell{
public:
	PoisonGas(int duration);
	int Cast(Humanoid *caster, Creature* enemy);
};

