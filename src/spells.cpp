#include "spells.h"
// Spell parent class implementations

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

int Fireball::cast(Humanoid* caster, Creature* enemy){
    return enemy->damage((caster->getWeapon()==nullptr)?10:10*caster->getWeapon()->getMagicAdjust());
}

PoisonGas::PoisonGas(int duration):Spell(duration){}

int PoisonGas::cast(Humanoid *caster, Creature *enemy){
    return enemy->damage((caster->getWeapon()==nullptr)?2:2*caster->getWeapon()->getMagicAdjust());
}
// Poison Gas class implementations

Debuff::Debuff(int duration, int strength, int maxHp) : Spell(duration){
    this->strength = strength;
    this->maxHp = maxHp;
}

int Debuff::getStrength() const {
    return this->strength;
}

int Debuff::getMaxHp() const {
    return this->maxHp;
}

int Debuff::cast(Humanoid *caster, Creature *enemy) {
    auto * hCaster = (Humanoid *) caster;
    int strengthDebuff = this->strength;
    int maxHpDebuff = this->maxHp;
    if(hCaster->getWeapon() != nullptr && hCaster->getWeapon()->getMagicAdjust() != 0) {
        strengthDebuff = (int) round((float) strengthDebuff * hCaster->getWeapon()->getMagicAdjust());
        maxHpDebuff = (int) round((float) maxHpDebuff * hCaster->getWeapon()->getMagicAdjust());
    }
    enemy->setStrength(enemy->getStrength() - strengthDebuff);
    enemy->setMaxHp(enemy->getMaxHp() - maxHpDebuff);
    if(enemy->getHp() > enemy->getMaxHp())
        enemy->setHp(enemy->getMaxHp());
		return 1;
}

//Erase class implementation

Erase::Erase(int duration) : Spell(duration){}
/*
int Erase::cast(Humanoid *caster, Creature *enemy) {
    int i = 0;
    auto * hCaster = (Humanoid *) caster;
    if (hCaster->getWeapon() != nullptr && hCaster->getWeapon()->getMagicAdjust() > 0)
        i++;
    for (int j = 0; j <= i; ++j) {
        Inventory * newInv = enemy->getInventory();
        newInv->deleteElementByIndex((rand() % (newInv->getElements().size())));
        enemy->setInventory(newInv);
    }
		return 1;
}*/
int Erase::cast(Humanoid *caster, Creature *enemy) {}

//I commented this, Because I can't run it yet
