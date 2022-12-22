//
// Created by Apor Biro on 23.11.2022.
//
#include "Game.h"

Creature::Creature(const string& name, int hp, int maxHp, int strength,vector<Effect*>effect){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
		effects = effect;
    //this->inventory = new Inventory();
}

void Creature::setName(const string& name){
    this->name = name;
}

void Creature::setHp(int hp){
		this->hp = hp<0?0:(hp>maxHp?maxHp:hp);
}

void Creature::setMaxHp(int maxHp){
    this->maxHp = maxHp;
}

void Creature::setStrength(int strength){
    this->strength = strength;
}

int Creature::affect(){
	for(int i=0;i<effects.size();i++){
		if(!effects[i]->affect(this)) return 0;
		if(!effects[i]->getDuration()){
			delete effects[i];
			effects.erase(effects.begin()+i--);
		}
	}
	return 1;
}

void Creature::addEffect(Effect *effect){
	effects.push_back(effect);
}	

void Humanoid::setInventory(Inventory* inventory) {
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

Inventory* Humanoid::getInventory() const {
    return this->inventory;
}

// Do Creatures have an Inventory? - Ede

bool Creature::attack(Creature* enemy) const{
		return enemy->damage(strength);
}

int Creature::damage(int dmg){
    setHp(hp-dmg);
	return getHp();
}


bool Humanoid::addElementToInventory(Slot* element) {
    return this->inventory->addElement(element);
}

int Humanoid::useElementFromInventoryByIndex(int index, Humanoid * player, Creature * enemy) {
    return this->inventory->useElementByIndex(index, player, enemy);
}

// Humanoid functions implementation

Humanoid::Humanoid(const string& name, int hp, int maxHp, int strength, vector<Effect*> effect, Armor *armor, Weapon *weapon):Creature(name,hp,maxHp,strength,effect){
    this->armor = armor;
    this->weapon = weapon;
		inventory = new Inventory();
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
    return enemy->damage((getWeapon()==nullptr)?strength:strength*getWeapon()->getDamage());
}

int Humanoid::damage(int dmg){
	setHp((getArmor()==nullptr)?hp-dmg:hp-max(dmg-armor->getDefense(),0));
    return getHp();
}

int Creature::turn(Creature* enemy){
    return attack(enemy);
}

int Humanoid::turn(Creature* enemy){
		cerr<<"WhatToDo\n";
		cerr<<"1:Attack\n";
		cerr<<"2:Use Something\n";
    int move;
		cin>>move;
    switch (move) {
            case 1: return attack(enemy);
                break;
            case 2:
								if(getInventory()->getElements().size()==0) break;
								getInventory()->printElements();
                int chosen; // = getSpellType;
								cin>>chosen;
								return useElementFromInventoryByIndex(chosen,this,enemy);
        }
		return 1;
}

