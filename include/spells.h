#pragma once
#include "creature.h"

class Creature;

class Spell{
    int duration;
public:
    Spell(int duration);
    void setDuration(int duration);
    int getDuration() const;
};

class Fireball: public Spell{
    static int damage;
public:
    bool cast(Creature *caster, Creature* enemy);
};

class PoisonGas: public Spell{
    static int damage;
public:
	static bool cast(Creature *caster, Creature* enemy);
};

