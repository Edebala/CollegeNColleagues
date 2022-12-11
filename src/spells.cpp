#include "../include/spells.h"

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

Fireball::Fireball(int duration) : Spell(duration) {}

int Fireball::getDamage() const{
    return Fireball::damage;
}

bool Fireball::cast(Creature* caster, Creature* enemy){
    auto * hCaster = (Humanoid *) caster;
    auto * hEnemy = (Humanoid *) enemy;
    int finalDamage = Fireball::damage;
    if(hCaster->getWeapon() != nullptr && hCaster->getWeapon()->getMagicAdjust() != 0)
        finalDamage = (int)round((float)finalDamage * hCaster->getWeapon()->getMagicAdjust());
    else if(hEnemy->getArmor() != nullptr)
        finalDamage -= hEnemy->getArmor()->getDefense();
    if(finalDamage > 0)
        hEnemy->setHp(hEnemy->getHp() - finalDamage);
    if(hEnemy->getHp() > 0)
        return false;
    else
        return true;
}

// Poison Gas class implementations

int PoisonGas::damage = 2;

PoisonGas::PoisonGas(int duration) : Spell(duration){}

int PoisonGas::getDamage() const {
    return PoisonGas::damage;
}

bool PoisonGas::cast(Creature *caster, Creature *enemy){
    auto * hCaster = (Humanoid *) caster;
    auto * hEnemy = (Humanoid *) enemy;
    int finalDamage = PoisonGas::damage;
    if(hCaster->getWeapon() != nullptr && hCaster->getWeapon()->getMagicAdjust() != 0)
        finalDamage = (int)round((float)finalDamage * hCaster->getWeapon()->getMagicAdjust());
    else if(hEnemy->getArmor() != nullptr)
        finalDamage -= hEnemy->getArmor()->getDefense();
    if(finalDamage > 0)
        hEnemy->setHp(hEnemy->getHp() - finalDamage);
    if(hEnemy->getHp() > 0)
        return false;
    else
        return true;
}

// Debuff class implementation

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

void Debuff::cast(Creature *caster, Creature *enemy) {
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
}

