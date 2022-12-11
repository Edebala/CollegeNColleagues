//
// Created by Apor Biro on 23.11.2022.
//

#include "../include/items.h"

// Item class implementations

Item::Item(const string& name){
    this->name = name;
}

void Item::setName(const string& name) {
    this->name = name;
}

string Item::getName(){
    return this->name;
}

// Weapon class implementations

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

// Potion class implementation

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

// EquipmentBuffPotion class implementation

EquipmentBuffPotion::EquipmentBuffPotion(const string &name, int duration, int amount) : Potion(name, duration){
    this->amount = amount;
}

int EquipmentBuffPotion::getAmount() const {
    return this->amount;
}

void EquipmentBuffPotion::use(Item * item) const {
    Weapon * wItem = (Weapon*) item;
    Armor * aItem = (Armor*) item;

    if(wItem->getDamage() != 0)
        wItem->setDamage(wItem->getDamage() + this->amount);
    else if(aItem->getDefense() != 0)
        aItem->setDefense(aItem->getDefense() + this->amount);
    else
        cout << "Potion is not applicable on this item!" << endl;
}

//StrengthenPotion class implementation

StrengthenPotion::StrengthenPotion(const string &name, int duration, int amount) : Potion(name, duration){
    this->amount = amount;
}

int StrengthenPotion::getAmount() const {
    return this->amount;
}

void StrengthenPotion::use(Creature *creature) const {
    creature->setStrength(creature->getStrength() + this->amount);
}




