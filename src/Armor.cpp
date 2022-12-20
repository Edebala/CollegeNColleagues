#include "Armor.h"

// Armor class implementations

Armor::Armor(const string& name, int defense) : Item(name) {
    this->defense = defense;
}

void Armor::setDefense(int defense) {
    this->defense = defense;
}

int Armor::getDefense() const{
    return this->defense;
}
