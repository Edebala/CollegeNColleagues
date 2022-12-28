#include "Game.h"

// Weapon class implementations
//
Weapon::Weapon(const string& name, int damage) : Item(name) {
    this->damage = damage;
}

Weapon::Weapon(const string &name, float magicAdjust, int damage) : Item(name) {
    this->damage = damage;
    this->magicAdjust = magicAdjust;
}

void Weapon::setDamage(int damage) {
    this->damage = damage;
}

int Weapon::getDamage() const {
    return this->damage;
}

float Weapon::getMagicAdjust() const {
    return this->magicAdjust;
}

int Weapon::use(Humanoid* user, Creature* Enemy){
	if(user->getWeapon()!=NULL)
		user->addElementToInventory(user->getWeapon());
	user->setWeapon(this);
	return 1;
}
