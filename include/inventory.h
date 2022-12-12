#pragma once
#include "../include/items.h"
#include "../include/spells.h"
#include <vector>
#include <variant>

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
using MultiType = variant<Weapon*, Armor*, Throwable*, HealingPotion*, WeaponBuffPotion*, ArmorBuffPotion*, StrengthenPotion*, Fireball*, PoisonGas*, Debuff*, Erase*>;

class Inventory{
    vector<MultiType> elements;
    static int maxSize;
public:
    Inventory();
    void setElements(vector<MultiType> elements);
    vector<MultiType> getElements() const;
    bool addElement(MultiType element);
    void deleteElementByIndex(int index);
    static void useElementByIndex(int index, Creature * player, Creature * enemy);
};
