#include <string>

using namespace std;

class Item{
    string name;
    float magicAdjust;
public:
    Item(const string& name);
    string getName();
    void setName(const string& name);
    float getMagicAdjust() const;
};

class Weapon: public Item{
    int damage;
public:
    Weapon(const string& name, int damage);
    int getDamage() const;
};

class Armor: public Item{
    int defense;
public:
    Armor(const string& name, int defense);
    int getDefense() const;
};