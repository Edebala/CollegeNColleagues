#include <string>
#include <vector>
#include "items.h"
#include "effects.h"

using namespace std;

class Creature{
    string name;
    int hp, maxHp;
    int strength;
    vector<Effect> effect;
public:
    Creature(string name, int hp, int maxHp, int strength, vector<Effect> effect);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    
    int getHp();
    int getMaxHp();
    
    virtual bool attack(Creature *enemy);
};

class Humanoid: public Creature{
    Armor *armor;
    Weapon *weapon;
public:
    Humanoid(string name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Tool *weapon);
    
    int castSpell(Spell*, Enemy*);
    int useItem();
    
    bool attack(Creature *enemy);
};

// Creature

Creature::Creature(string name, int hp, int maxHp, int strength, vector<Effect> effect){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
    this->effect = effect;
}

void Creature::setHp(int hp){
    this->hp = hp;
}

void Creature::setMaxHp(int maxHp){
    this->maxHp = maxHp;
}

int Creature::getHp(){
    return this->hp;
}

int Creature::getMaxHp(){
    return this->maxHp;
}

void Creature::attack(Creature *enemy){
    enemy->setHp(enemy->getHp - this->strength);
}

// Humanoid

Humanoid::Humanoid(string name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Tool *weapon) :
Creature(name, hp, maxhp, strength, effect){
    this->armor = armor;
    this->weapon = weapon;
}



