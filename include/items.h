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

class Weapon: public Item{
    int damage;
    float magicAdjust = 0;
public:
    Weapon(const string& name, int damage);
    Weapon(const string& name, float magicAdjust, int damage);
    void setDamage(int damage);
    int getDamage() const;
    float getMagicAdjust() const;
};

class Armor: public Item{
    int defense;
public:
    Armor(const string& name, int defense);
    void setDefense(int defense);
    int getDefense() const;
};

class Throwable: public Item{
    int damage;
public:
    Throwable(const string& name, int damage);
    int getDamage() const;
    bool use(Creature *enemy) const;
};

class Potion: public Item{
    int duration;
public:
    Potion(const string& name, int duration);
    int getDuration() const;
};

class HealingPotion : public Potion{
    int hp;
public:
    HealingPotion(const string& name, int duration, int hp);
    int getHp() const;
    void use(Creature * creature) const;
};

class EquipmentBuffPotion: public Potion{
    int amount;
public:
    EquipmentBuffPotion(const string& name, int duration, int amount);
    int getAmount() const;
    void use(Item * item) const;
};

class StrengthenPotion: public Potion{
    int amount;
public:
    StrengthenPotion(const string& name, int duration, int amount);
    int getAmount() const;
    void use(Creature * creature) const;
};