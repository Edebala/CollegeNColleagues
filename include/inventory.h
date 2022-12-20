#pragma once
#include "items.h"
#include "spells.h"
#include <vector>

class Weapon;
class Armor;
class Throwable;
class HealingPotion;
class WeaponBuffPotion;
class ArmorBuffPotion;
class StrengthenPotion;
class Fireball;
class PoisonGas;
class Debuff;
class Erase;

using namespace std;

class Inventory{
    vector<Slot*> elements;
    static int maxSize;
public:
    Inventory();
    void setElements(vector<Slot*> elements);
    vector<Slot*> getElements() const;
    bool addElement(Slot* element);
    void deleteElementByIndex(int index);
    static void useElementByIndex(int index, Creature * player, Creature * enemy);
};
