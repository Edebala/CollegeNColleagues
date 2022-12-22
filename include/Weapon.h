#pragma once
#include <string>
class Item;

class Weapon: public Item{
    int damage = 0;
    float magicAdjust = 1;
public:
    Weapon(const string& name, int damage);
    Weapon(const string& name, float magicAdjust, int damage);
    void setDamage(int damage);
    int getDamage() const;
    float getMagicAdjust() const;
		int use(Humanoid* user, Creature* Enemy);
};
