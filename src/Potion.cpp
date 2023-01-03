#include "Game.h"
// Potion parent class implementation

Potion::Potion(string name, int duration) : Item(name) {
    this->duration = duration;
}

int Potion::getDuration() const {
    return this->duration;
}

// HealingPotion class implementation

HealingPotion::HealingPotion(string name, int duration, int hp) : Potion(name, duration){
    this->hp = hp;
}

int HealingPotion::getHp() const {
    return this->hp;
}

int HealingPotion::use(Humanoid* user,Creature *enemy){
		user->addEffect(new Regeneration(duration,hp));
		return 1;
}

// BuffPotion parent class implementation

BuffPotion::BuffPotion(string name, int duration, int amount) : Potion(name, duration){
    this->amount = amount;
}

int BuffPotion::getAmount() const {
    return this->amount;
}

// WeaponBuffPotion class implementation

WeaponBuffPotion::WeaponBuffPotion(string name, int duration, int amount) : BuffPotion(name, duration, amount){}

int WeaponBuffPotion::use(Humanoid* user, Creature* enemy) const {
    user->getWeapon()->setDamage(user->getWeapon()->getDamage() + this->getAmount());
		return 1;
}

// ArmorBuffPotion class implementation

ArmorBuffPotion::ArmorBuffPotion(string name, int duration, int amount) : BuffPotion(name, duration, amount){}

int ArmorBuffPotion::use(Humanoid* user, Creature* enemy) const{
    user->getArmor()->setDefense(user->getArmor()->getDefense() + this->getAmount());
}

// StrengthenPotion class implementation

StrengthenPotion::StrengthenPotion(string name, int duration, int amount) : Potion(name, duration){
    this->amount = amount;
}

int StrengthenPotion::getAmount() const {
    return this->amount;
}

int StrengthenPotion::use(Humanoid* user,Creature *enemy) const {
    user->setStrength(enemy->getStrength() + this->amount);
		return 1;
}

