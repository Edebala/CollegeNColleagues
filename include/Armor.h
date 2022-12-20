#pragma once
#include "items.h"

class Armor: public Item{
    int defense = 0;
public:
    Armor(const string& name, int defense);
    void setDefense(int defense);
    int getDefense() const;
};

