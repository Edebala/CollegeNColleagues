#pragma once
#include "creature.h"
#include <iostream>
#include <string>

using namespace std;
class Creature;

class Item{
    string name;
public:
    Item(const string& name);
    string getName();
    void setName(const string& name);
};

// Equipment items

class Weapon: public Item{
    int damage = 0;
    float magicAdjust = 0;
public:
    Weapon(const string& name, int damage);
    Weapon(const string& name, float magicAdjust, int damage);
    void setDamage(int damage);
    int getDamage() const;
    float getMagicAdjust() const;
};

class Armor: public Item{
    int defense = 0;
public:
    Armor(const string& name, int defense);
    void setDefense(int defense);
    int getDefense() const;
};

// Usable items

class Throwable: public Item{
    int damage = 0;
public:
    Throwable(const string& name, int damage);
    int getDamage() const;
    bool use(Creature *enemy) const;
};

class Potion: public Item{
    int duration = 0;
public:
    Potion(const string& name, int duration);
    int getDuration() const;
};

class HealingPotion : public Potion{
    int hp = 0;
public:
    HealingPotion(const string& name, int duration, int hp);
    int getHp() const;
    void use(Creature * creature) const;
};

class WeaponBuffPotion: public Potion{
    int amount = 0;
    int isForWeapon = 0;
public:
    WeaponBuffPotion(const string& name, int duration, int amount);
    int getAmount() const;
    int getIsForWeapon() const;
    void use(Weapon * weapon) const;
};

class ArmorBuffPotion: public Potion{
    int amount = 0;
    int isForWeapon = 0;
public:
    ArmorBuffPotion(const string& name, int duration, int amount);
    int getAmount() const;
    int getIsForWeapon() const;
    void use(Armor * armor) const;
};

class StrengthenPotion: public Potion{
    int amount = 0;
public:
    StrengthenPotion(const string& name, int duration, int amount);
    int getAmount() const;
    void use(Creature * creature) const;
};