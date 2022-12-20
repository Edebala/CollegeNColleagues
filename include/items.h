#pragma once
#include <string>
#include "Slot.h"

class Humanoid;
class Creature;
class Slot;

using namespace std;

class Item: public Slot{
    string name;
protected:
    Item(const string& name);
    string getName();
    void setName(const string& name);
		virtual int use(Humanoid* user,Creature* Enemy)=0;
};

// Equipment items

// Usable items

class Throwable: public Item{
    int damage = 0;
public:
    Throwable(const string& name, int damage);
    int getDamage() const;
    int use(Humanoid* user,Creature *enemy) const;
};
