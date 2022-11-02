#include <string>

using namespace std;

class Item{
    string name;
public:
    Item(string name);
    string getName();
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
