#pragma once
#include <string>
class Item;

class Armor: public Item{
    int defense = 0;
public:
    Armor(const string& name, int defense);
    void setDefense(int defense);
    int getDefense() const;
		int use(Humanoid* user, Creature* Enemy);
};

