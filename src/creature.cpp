//
// Created by Apor Biro on 23.11.2022.
//
#include "../include/creature.h"

Creature::Creature(const string& name, int hp, int maxHp, int strength, vector<Effect> effect){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
    this->effect = effect;
}

void Creature::setName(const string& name){
    this->name = name;
}

void Creature::setHp(int hp){
    this->hp = hp;
}

void Creature::setMaxHp(int maxHp){
    this->maxHp = maxHp;
}

void Creature::setStrength(int strength){
    this->strength = strength;
}

void Creature::setEffect(vector<Effect> effect){
    this->effect = effect;
}

string Creature::getName(){
    return this->name;
}

int Creature::getHp() const{
    return this->hp;
}

int Creature::getMaxHp() const{
    return this->maxHp;
}

int Creature::getStrength() const {
    return this->strength;
}

vector<Effect> Creature::getEffect() const {
    return this->effect;
}

bool Creature::attack(Humanoid* enemy) const{
    int enemyHp = enemy->getHp();
    int strength = this->getStrength();
    int armor = enemy->getArmor()->getDefense();
    int damage = strength - armor;

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

void Creature::setTurn(bool turn) {
    this->turn = turn;
}

bool Creature::getTurn() const {
    return this->turn;
}

// Humanoid functions implementation

Humanoid::Humanoid(const string& name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Weapon *weapon)
        : Creature(name, hp, maxHp, strength, effect){
    this->armor = armor;
    this->weapon = weapon;
}

void Humanoid::setArmor(Armor* armor){
    this->armor = armor;
}

void Humanoid::setWeapon(Weapon* weapon){
    this->weapon = weapon;
}

Weapon* Humanoid::getWeapon() const{
    return this->weapon;
}

Armor* Humanoid::getArmor() const{
    return this->armor;
}

bool Humanoid::attack(Creature *enemy) const {
    int enemyHp = enemy->getHp();
    int strength = this->getStrength();
    int weaponDamage = this->weapon->getDamage();
    int damage = strength + weaponDamage;

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