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
    Creature(string name, int hp, int maxHp, int strength, vector<Effect> effect);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    
    int getHp() const;
    int getMaxHp() const;
    int getStrength() const;

    bool attack(Humanoid *enemy);
};

class Humanoid{
    string name;
    int hp, maxHp;
    int strength;
    vector<Effect> effect;
    Armor *armor;
    Weapon *weapon;
public:
    Humanoid(string name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Weapon *weapon);

    int getHp() const;
    int getStrength() const;
    int getWeaponDmg() const;
    int getArmorDfs() const;

    void setHp(int hp);

//    int castSpell(Spell*, Enemy*);
//    int useItem();

    bool attack(Creature *enemy);
};

// Creature functions implementation

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

int Creature::getHp() const{
    return this->hp;
}

int Creature::getMaxHp() const{
    return this->maxHp;
}

int Creature::getStrength() const {
    return this->strength;
}

bool Creature::attack(Humanoid* enemy){
    int enemyHp = enemy->getHp();
    int strength = this->getStrength();
    int armor = enemy->getArmorDfs();
    int damage = 2 * strength / armor;

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

Humanoid::Humanoid(string name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Weapon *weapon){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
    this->effect = effect;
    this->armor = armor;
    this->weapon = weapon;
}

int Humanoid::getHp() const{
    return this->hp;
}

int Humanoid::getStrength() const{
    return this->strength;
}

int Humanoid::getWeaponDmg() const{
    return this->weapon->getDamage();
}

int Humanoid::getArmorDfs() const{
    return this->armor->getDefense();
}

void Humanoid::setHp(int hp){
    this->hp = hp;
}

bool Humanoid::attack(Creature *enemy) {
    int enemyHp = enemy->getHp();
    int strength = this->getStrength();
    int weaponDamage = this->getWeaponDmg();
    int damage = 2 * strength * weaponDamage;

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



