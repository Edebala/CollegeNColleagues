#pragma once
#include <string>
#include <vector>
#include "items.h"
#include "effects.h"

using namespace std;
class Humanoid;

class Creature{
    string name;
    int hp, maxHp;
    int strength;
    vector<Effect> effect;
public:
    Creature(const string& name, int hp, int maxHp, int strength, vector<Effect> effect);
    
	// setters
	void setName(const string& name);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setStrength(int strength);
    void setEffect(vector<Effect> effect);

	// getters
    string getName();
    int getHp() const;
    int getMaxHp() const;
    int getStrength() const;
    vector<Effect> getEffect() const;

	// actions
    bool attack(Humanoid *enemy) const;
};

class Humanoid : public Creature{
    Armor *armor;
    Weapon *weapon;
public:
    Humanoid(const string& name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Weapon *weapon);

	//setters
    void setArmor(Armor* armor);
    void setWeapon(Weapon* weapon);

	// getters
    Weapon* getWeapon() const;
    Armor* getArmor() const;
    	
	//actions
	//bool castSpell(Spell*, Creature*);
	bool attack(Creature *enemy) const;
	bool useItem(Item*, Creature*);
	bool useItem(Item*, Humanoid*);
};

// Creature functions implementation

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

    if(enemyHp != enemy->getHp())
        return true;
    else
        return false;
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

    if(enemyHp != enemy->getHp())
        return true;
    else
        return false;
}


