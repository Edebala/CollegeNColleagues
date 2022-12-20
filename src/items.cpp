//
// Created by Apor Biro on 23.11.2022.
//

#include "items.h"

// Item parent class implementations

Item::Item(const string& name){
    this->name = name;
}

void Item::setName(const string& name) {
    this->name = name;
}

string Item::getName(){
    return this->name;
}


// Throwable class implementations

Throwable::Throwable(const string& name, int damage) : Item(name) {
    this->damage = damage;
}

int Throwable::getDamage() const {
    return this->damage;
}

bool Throwable::use(Creature *enemy) const{
    int enemyHp = enemy->getHp();
    int damage = this->damage;

    int newEnemyHp;
    if(enemyHp > damage)
        newEnemyHp = enemyHp - damage;
    else
        newEnemyHp = 0;

    enemy->setHp(newEnemyHp);

    if(enemy->getHp() > 0)
        return false;
    else
        return true;
}
