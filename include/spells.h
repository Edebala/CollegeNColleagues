#pragma once
#include "creature.h"
#include <cmath>
#include <random>

class Creature;
class Humanoid;

class Spell{
    int duration = 0;
public:
    Spell(int duration);
    void setDuration(int duration);
    int getDuration() const;
		virtual int cast(Humanoid *caster, Creature* enemy) = 0;
};

// Damaging spells

class Fireball: public Spell{
    static int damage;
public:
		Fireball();
    int cast(Humanoid *caster, Creature* enemy);
    int getDamage() const;
};

class PoisonGas: public Spell{
    static int damage;
public:
	PoisonGas(int duration);
	int cast(Humanoid *caster, Creature* enemy);
};

// Debuff spells

class Debuff: public Spell{
    int strength = 0;
    int maxHp = 0;
public:
    Debuff(int duration, int strength, int maxHp);
    int getStrength() const;
    int getMaxHp() const;
    int cast(Humanoid *caster, Creature* enemy);
};

class Erase: public Spell{
public:
    Erase(int duration);
    int cast(Humanoid * caster, Creature * enemy);
};
