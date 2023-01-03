#pragma once
#include <string>

using namespace std;
class Item;

class Potion: public Item{
protected:
    int duration = 0;
public:
    Potion(string name, int duration);
    int getDuration() const;
};

class HealingPotion : public Potion{
    int hp = 0;
public:
    HealingPotion(string name, int duration, int hp);
    int getHp() const;
    int use(Humanoid* user,Creature * creature);
};

class BuffPotion: public Potion{
    int amount = 0;
public:
    BuffPotion(string name, int duration, int amount);
    int getAmount() const;
};

class WeaponBuffPotion: public BuffPotion{
public:
    WeaponBuffPotion(string name, int duration, int amount);
    int use(Humanoid* user,Creature* Enemy) const;
};

class ArmorBuffPotion: public BuffPotion{
public:
    ArmorBuffPotion(string name, int duration, int amount);
    int use(Humanoid* user,Creature* Enemy) const;
};

class StrengthenPotion: public Potion{
    int amount = 0;
public:
    StrengthenPotion(string name, int duration, int amount);
    int getAmount() const;
    int use(Humanoid* user,Creature * enemy) const;
};
