//
// Created by Apor Biro on 23.11.2022.
//
#include "../include/creature.h"

Creature::Creature(const string& name, int hp, int maxHp, int strength){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
    this->inventory = vector<INV>();
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

void Creature::setTurn(bool turn) {
    this->turn = turn;
}

void Creature::setInventory(vector<INV> inventory) {
    this->inventory = inventory;
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

bool Creature::getTurn() const {
    return this->turn;
}

vector<INV> Creature::getInventory() const {
    return this->inventory;
}

bool Creature::attack(Creature* enemy) const{
    Humanoid * hEnemy = (Humanoid*) enemy;
    int enemyHp = enemy->getHp();
    int strength = this->getStrength();

    int armor = 0;
    if (hEnemy->getArmor() != nullptr)
        armor = hEnemy->getArmor()->getDefense();
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

void Creature::addToInventory(Spell * newElement) {
    INV newInvEl;
    newInvEl.spell = newElement;
    this->inventory.emplace_back(newInvEl);
}

void Creature::addToInventory(Item *newElement) {
    INV newInvEl;
    newInvEl.item = newElement;
    this->inventory.emplace_back(newInvEl);
}

void Creature::useElementFromInventoryByIndex(int index, Creature * player, Creature * enemy) {
    vector<INV> inv = player->getInventory();
    INV element = inv.at(index);
    Humanoid * hPlayer = (Humanoid*) player;

    if(element.item != nullptr){
        Item * parentItem = element.item;

        auto childThrowable = (Throwable*) parentItem;
        auto childHealingPotion = (HealingPotion*) parentItem;
        auto childWeaponBuffPotion = (WeaponBuffPotion*) parentItem;
        auto childArmorBuffPotion = (ArmorBuffPotion*) parentItem;
        auto childStrengthenPotion = (StrengthenPotion*) parentItem;

        if(childThrowable->getDamage() != 0)
            childThrowable->use(enemy);
        else if (childWeaponBuffPotion->getIsForWeapon() == 1 && hPlayer->getWeapon() != nullptr)
            childWeaponBuffPotion->use(hPlayer->getWeapon());

        inv.erase(inv.begin() + index);
        player->setInventory(inv);
    }
}

// Humanoid functions implementation

Humanoid::Humanoid(const string& name, int hp, int maxHp, int strength, Armor *armor, Weapon *weapon)
        : Creature(name, hp, maxHp, strength){
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
    int damage = this->weapon->getDamage();

    int newEnemyHp;
    if(enemyHp > damage)
        newEnemyHp = enemyHp - damage;
    else
        newEnemyHp = 0;

    enemy->setHp(newEnemyHp);

    return Creature::attack(enemy);
}