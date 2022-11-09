#include <string>

using namespace std;
class Item;

class Item{
    string name;
public:
    Item(const string& name);
    string getName();
    void setName(string name);
};

class Weapon: public Item{
	int damage;
	use();	//Equip
	Weapon();
};

class Armor: public Item{
	int defense;
public:
	use();	//Equip
	getDefense();
	Armor();
};

//Ez nem a Headerbe valo
Item::Item(string name){
    this->name = name;
};

//Ez nem a Headerbe valo
string Item::getName(){
    return this->name;
};

class Consumable: public Item{
	public:
		use();
};

class Throwable: public Consumable{
	int dmg;
};

 Usable: public Consumable{
public:
	
};

void Item::setName(string name) {
    this->name = name;
}

string Item::getName(){
    return this->name;
}

class Weapon: public Item{
	int damage;
public:
    Weapon(const string& name, int damage);
    int getDamage() const;
};

Weapon::Weapon(const string& name, int damage) : Item(name) {
    this->damage = damage;
}

int Weapon::getDamage() const {
    return this->damage;
}

class Armor: public Item{
	int defense;
public:
    Armor(const string& name, int defense);
    int getDefense() const;
};

Armor::Armor(const string& name, int defense) : Item(name) {
    this->defense = defense;
}

int Armor::getDefense() const{
    return this->defense;
}
