#pragma once
#include "creature.h"

class Creature;

class Spell{
    int duration;
public:
    Spell(int duration);
    void setDuration(int duration);
    void getDuration() const;
};

Spell::Spell(int duration) {
    this->duration = duration;
}

void Spell::setDuration(int duration) {
    this->duration = duration;
}

void Spell::getDuration() const {
    return this->duration;
}

class Fireball: public Spell{
public:
    int Cast(Creature *caster, Creature* enemy);
}

int Fireball::Cast(Creature* caster, Creature* enemy){
    enemy->damage(5*caster.tool.getMagicAdjust());
}

class PoisonGas: public Spell{
public:
	int Cast(Creature *caster, Creature* enemy);
}

int PoisonGas::Cast(Creature *caster, Creature *enemy){
    enemy->damage(2*caster.tool.getMagicAdjust());
}

