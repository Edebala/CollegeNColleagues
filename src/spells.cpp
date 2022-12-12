#include "spells.h"

Spell::Spell(int duration) {
    this->duration = duration;
}

void Spell::setDuration(int duration) {
    this->duration = duration;
}

int Spell::getDuration() const {
    return this->duration;
}

Fireball::Fireball():Spell(0){}

int Fireball::Cast(Humanoid* caster, Creature* enemy){
    return enemy->damage(5*caster->getWeapon()->getMagicAdjust());
}

PoisonGas::PoisonGas(int duration):Spell(duration){}

int PoisonGas::Cast(Humanoid *caster, Creature *enemy){
    return enemy->damage(2*caster->getWeapon()->getMagicAdjust());
}

