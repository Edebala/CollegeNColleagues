#pragma once
#include <vector>

class Slot;
class Creature;
class Humanoid;
class Item;
class Spell;

using namespace std;

class Inventory{
    vector<Slot*> elements;
    static long unsigned int maxSize;
public:
    Inventory();
    void setElements(vector<Slot*> elements);
    vector<Slot*> getElements() const;
    bool addElement(Slot* element);
    void deleteElementByIndex(int index);
    static void useElementByIndex(int index, Humanoid * player, Creature * enemy);
};
