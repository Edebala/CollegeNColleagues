#pragma once
#include "Slot.h"
#include "creature.h"
#include <cmath>
#include <random>

class Creature;

class Spell: public Slot{
    int duration = 0;
public:
    Spell(int duration);
    void setDuration(int duration);
    int getDuration() const;
		virtual bool cast(Humanoid*,Creature*)=0;
		void use(Humanoid* user,Creature* enemy){cast(user,enemy);}
};

// Damaging spells

class Fireball: public Spell{
    static int damage;
public:
    Fireball(int duration);
    int getDamage() const;
};

class PoisonGas: public Spell{
    static int damage;
public:
    PoisonGas(int duration);
    int getDamage() const;
};

// Debuff spells

class Debuff: public Spell{
    int strength = 0;
    int maxHp = 0;
public:
    Debuff(int duration, int strength, int maxHp);
    int getStrength() const;
    int getMaxHp() const;
};

class Erase: public Spell{
public:
    Erase(int duration);
};
