#pragma once
#include "items.h"

class Weapon: public Item{
    int damage = 0;
    float magicAdjust = 0;
public:
    Weapon(const string& name, int damage);
    Weapon(const string& name, float magicAdjust, int damage);
    void setDamage(int damage);
    int getDamage() const;
    float getMagicAdjust() const;
		int use(Humanoid* user, Creature* Enemy);
};
