#pragma once
#include "creature.h"
#include <iostream>
#include <string>

using namespace std;
class Creature;

class Item:public Slot{
    string name;
protected:
    Item(const string& name);
    string getName();
    void setName(const string& name);
		virtual void use(Humanoid* user,Creature* Enemy);
};

// Equipment items

// Usable items

class Throwable: public Item{
    int damage = 0;
public:
    Throwable(const string& name, int damage);
    int getDamage() const;
    bool use(Humanoid* user,Creature *enemy) const;
};

