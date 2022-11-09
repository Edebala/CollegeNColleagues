#include <string>

using namespace std;
class Item;

class Item{
    string name;
public:
    Item(string name);
    string getName();
};

class Weapon: public Item{
	int damage;
};

class Armor: public Item{
	int defense;
};

Item::Item(string name){
    this->name = name;
}

string Item::getName(){
    return this->name;
}
