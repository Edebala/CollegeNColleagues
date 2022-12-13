//
// Created by Apor Biro on 23.11.2022.
//
#include "creature.h"

Creature::Creature(const string& name, int hp, int maxHp, int strength,vector<Effect>effect){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
    //this->inventory = new Inventory();
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

/*void Creature::setInventory(Inventory* inventory) {
    this->inventory = inventory;
}*/

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

/*Inventory* Creature::getInventory() const {
    return this->inventory;
}*/

// Do Creatures have an Inventory? - Ede

bool Creature::attack(Creature* enemy) const{
		return(enemy->damage(strength));
}

int Creature::damage(int dmg){
	return (hp-=dmg) < 1;
}

/*
bool Creature::addElementToInventory(MultiType element) {
    return this->inventory->addElement(element);
}

void Creature::useElementFromInventoryByIndex(int index, Creature * player, Creature * enemy) {
    this->inventory->useElementByIndex(index, player, enemy);
}
*/
// Humanoid functions implementation

Humanoid::Humanoid(const string& name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Weapon *weapon):Creature(name,hp,maxHp,strength,effect){
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

bool Humanoid::attack(Creature *enemy) const{
		return(enemy->damage((getWeapon()==nullptr)?strength:strength*getWeapon()->getDamage()));
}

int Humanoid::damage(int dmg){
	return (hp=max(hp-dmg/armor->getDefense(),0));
}
								
