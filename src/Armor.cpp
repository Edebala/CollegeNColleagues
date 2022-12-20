#include "Game.h"

// Armor class implementations

Armor::Armor(const string& name, int def) : Item(name) {
    defense = def;
}

void Armor::setDefense(int defense) {
    this->defense = defense;
}

int Armor::getDefense() const{
    return this->defense;
}

int Armor::use(Humanoid* user, Creature* Enemy){
	user->addElementToInventory(user->getArmor());
	user->setArmor(this);
}
