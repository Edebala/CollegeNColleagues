#pragma once
#include "items.h"

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
    int use(Humanoid* user,Creature * creature) const;
};

class BuffPotion: public Potion{
    int amount = 0;
public:
    BuffPotion(const string& name, int duration, int amount);
    int getAmount() const;
};

class WeaponBuffPotion: public BuffPotion{
public:
    WeaponBuffPotion(const string& name, int duration, int amount);
    int use(Humanoid* user,Creature* Enemy) const;
};

class ArmorBuffPotion: public BuffPotion{
public:
    ArmorBuffPotion(const string& name, int duration, int amount);
    int use(Humanoid* user,Creature* Enemy) const;
};

class StrengthenPotion: public Potion{
    int amount = 0;
public:
    StrengthenPotion(const string& name, int duration, int amount);
    int getAmount() const;
    int use(Humanoid* user,Creature * enemy) const;
};
