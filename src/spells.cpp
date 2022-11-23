#include "spells.h"

// Spell class implementations

Spell::Spell(int duration) {
    this->duration = duration;
}

void Spell::setDuration(int duration) {
    this->duration = duration;
}

int Spell::getDuration() const {
    return this->duration;
}

// Fireball class implementations

int Fireball::Cast(Creature* caster, Creature* enemy){

}

// Poison Gas class implementations

int PoisonGas::Cast(Creature *caster, Creature *enemy){

}
