#include "Potion.h"
// Potion parent class implementation

Potion::Potion(const string &name, int duration) : Item(name) {
    this->duration = duration;
}

int Potion::getDuration() const {
    return this->duration;
}

// HealingPotion class implementation

HealingPotion::HealingPotion(const string &name, int duration, int hp) : Potion(name, duration){
    this->hp = hp;
}

int HealingPotion::getHp() const {
    return this->hp;
}

void HealingPotion::use(Creature *creature) const{
    creature->setHp(creature->getHp() + this->hp);
}

// BuffPotion parent class implementation

BuffPotion::BuffPotion(const string &name, int duration, int amount) : Potion(name, duration){
    this->amount = amount;
}

int BuffPotion::getAmount() const {
    return this->amount;
}

// WeaponBuffPotion class implementation

WeaponBuffPotion::WeaponBuffPotion(const string &name, int duration, int amount) : BuffPotion(name, duration, amount){}

void WeaponBuffPotion::use(Weapon * weapon) const {
    weapon->setDamage(weapon->getDamage() + this->getAmount());
}

// ArmorBuffPotion class implementation

ArmorBuffPotion::ArmorBuffPotion(const string &name, int duration, int amount) : BuffPotion(name, duration, amount){}

void ArmorBuffPotion::use(Armor * armor) const{
    armor->setDefense(armor->getDefense() + this->getAmount());
}

// StrengthenPotion class implementation

StrengthenPotion::StrengthenPotion(const string &name, int duration, int amount) : Potion(name, duration){
    this->amount = amount;
}

int StrengthenPotion::getAmount() const {
    return this->amount;
}

void StrengthenPotion::use(Creature *creature) const {
    creature->setStrength(creature->getStrength() + this->amount);
}

