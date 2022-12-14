#pragma once
#include <string>
#include "Slot.h"

class Humanoid;
class Creature;
class Slot;

using namespace std;

class Item: public Slot{
public:
    Item(string);
		bool isSpell();
		virtual int use(Humanoid* user,Creature* Enemy)=0;
};

// Equipment items

// Usable items

class Throwable: public Item{
    int damage = 0;
public:
    Throwable(string, int damage);
    int getDamage() const;
    int use(Humanoid* user,Creature *enemy) const;
};
