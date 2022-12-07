#include "../include/spells.h"
#include <memory>

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

int Fireball::damage = 10;

bool Fireball::cast(Creature* caster, Creature* enemy){

}

// Poison Gas class implementations

int PoisonGas::damage = 2;

bool PoisonGas::cast(Creature *caster, Creature *enemy){
    auto * hCaster = (Humanoid *) &caster;
    auto * hEnemy = (Humanoid *) &enemy;
    int finalDamage = PoisonGas::damage;
    if(hCaster->getWeapon() != nullptr)
        finalDamage = (int)((float)finalDamage * hCaster->getWeapon()->getMagicAdjust());
    if(hEnemy->getArmor() != nullptr)
        finalDamage -= hEnemy->getArmor()->getDefense();
    hEnemy->setHp(hEnemy->getHp() - finalDamage);
    if(hEnemy->getHp() > 0)
        return false;
    else
        return true;
}
