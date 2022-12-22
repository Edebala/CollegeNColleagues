#include "Game.h"
//
// Created by Apor Biro on 23.11.2022.
//
// Item parent class implementations

Item::Item(const string& name): Slot(name){
}

string Item::getName(){
    return this->name;
}

bool Item::isSpell(){return false;}

// Throwable class implementations

Throwable::Throwable(const string& name, int damage) : Item(name) {
    this->damage = damage;
}

int Throwable::getDamage() const {
    return this->damage;
}

int Throwable::use(Humanoid* user, Creature *enemy) const{
		return(enemy->damage(this->damage));
}

