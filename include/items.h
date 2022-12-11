#include <string>

using namespace std;

class Item{
    string name;
public:
    Item(const string& name);
    string getName();
    void setName(const string& name);
};

class Weapon: public Item{
    int damage;
    float magicAdjust = 0;
public:
    Weapon(const string& name, int damage);
    Weapon(const string& name, float magicAdjust, int damage);
    int getDamage() const;
    float getMagicAdjust() const;
};

class Armor: public Item{
    int defense;
public:
    Armor(const string& name, int defense);
    int getDefense() const;
};

class Throwable: public Item{
    int damage;
public:
    Throwable(const string& name, int damage);
    int getDamage() const;
};

class Potion: public Item{
    int duration;
public:
    Potion(const string& name, int duration);
    int getDuration() const;
};