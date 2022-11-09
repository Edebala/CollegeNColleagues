#include <string>

using namespace std;
class Item;

class Item{
    string name;
public:
    Item(string name);
    string getName();
    void setName(string name);
};

Item::Item(string name){
    this->name = name;
}

void Item::setName(string name) {
    this->name = name;
}

string Item::getName(){
    return this->name;
}

class Weapon: public Item{
	int damage;
public:
    Weapon(string name, int damage);
    int getDamage() const;
};

Weapon::Weapon(string name, int damage) : Item(name) {
    this->damage = damage;
}

int Weapon::getDamage() const {
    return this->damage;
}

class Armor: public Item{
	int defense;
public:
    Armor(string name, int defense);
    int getDefense() const;
};

Armor::Armor(string name, int defense) : Item(name) {
    this->defense = defense;
}

int Armor::getDefense() const{
    return this->defense;
}