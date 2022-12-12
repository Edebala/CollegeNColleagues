#include "items.h"

Item::Item(const string& name){
    this->name = name;
}

void Item::setName(string name) {
    this->name = name;
}

string Item::getName(){
    return this->name;
}

Weapon::Weapon(const string& name, int damage) : Item(name) {
    this->damage = damage;
}

int Weapon::getDamage() const {
    return this->damage;
}

int Weapon::getMagicAdjust() const{
		return this->magicAdjust;
}

Armor::Armor(const string& name, int defense) : Item(name) {
    this->defense = defense;
}

int Armor::getDefense() const{
    return this->defense;
}
