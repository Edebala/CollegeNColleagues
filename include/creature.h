#pragma once
#include <string>
#include <vector>
#include "items.h"
#include "effects.h"

using namespace std;
class Humanoid;
class Weapon;
class Armor;

class Creature{
    string name;
    int hp, maxHp;
    int strength;
    vector<Effect> effect;
public:
    Creature(const string& name, int hp, int maxHp, int strength, vector<Effect> effect);
    void setName(const string& name);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setStrength(int strength);
    void setEffect(vector<Effect> effect);

    string getName();
    int getHp() const;
    int getMaxHp() const;
    int getStrength() const;
    vector<Effect> getEffect() const;

    bool attack(Humanoid *enemy) const;
};

class Humanoid{
    string name;
    int hp, maxHp;
    int strength;
    vector<Effect> effect;
    Armor *armor;
    Weapon *weapon;
public:
    Humanoid(const string& name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Weapon *weapon);

    void setName(const string& name);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setStrength(int strength);
    void setEffect(vector<Effect> effect);
    void setArmor(Armor* armor);
    void setWeapon(Weapon* weapon);

    int getHp() const;
    int getStrength() const;
    Weapon* getWeapon() const;
    Armor* getArmor() const;


//    int castSpell(Spell*, Enemy*);
//    int useItem();

    bool attack(Creature *enemy) const;
};

// Creature functions implementation

