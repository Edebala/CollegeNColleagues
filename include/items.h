#pragma once
#include <string>

using namespace std;

class Item{
    string name;
public:
    Item(const string& name);
    string getName();
    void setName(string name);
};

class Weapon: public Item{
    int damage,magicAdjust;
public:
    Weapon(const string& name, int damage);
    int getDamage() const;
    int getMagicAdjust() const;
};

class Armor: public Item{
    int defense;
public:
    Armor(const string& name, int defense);
    int getDefense() const;
};
