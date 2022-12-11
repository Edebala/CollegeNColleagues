#pragma once
#include "creature.h"
#include <cmath>

class Creature;

class Spell{
    int duration;
public:
    Spell(int duration);
    void setDuration(int duration);
    int getDuration() const;
};

// Damaging spells

class Fireball: public Spell{
    static int damage;
public:
    Fireball(int duration);
    int getDamage() const;
    bool cast(Creature *caster, Creature* enemy);
};

class PoisonGas: public Spell{
    static int damage;
public:
    PoisonGas(int duration);
    int getDamage() const;
    bool cast(Creature *caster, Creature* enemy);
};

// Debuff spells

class Debuff: public Spell{
    int strength = 0;
    int maxHp = 0;
public:
    Debuff(int duration, int strength, int maxHp);
    int getStrength() const;
    int getMaxHp() const;
    void cast(Creature *caster, Creature* enemy);
};