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
    int attack(Creature *enemy);
};

class Humanoid: public Creature{
    Armor *armor;
    Weapon *weapon;
public:
    Humanoid();
    int castSpell(Spell*,Enemy*);
    int useItem();
};

Creature::Creature(string name, int hp, int maxHp, int strength, vector<Effect> effect){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
    this->effect = effect;
}

Humanoid::Humanoid(string name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Tool *weapon) :
Creature(name, hp, maxhp, strength, effect){
    this->armor = armor;
    this->weapon = weapon;
}

