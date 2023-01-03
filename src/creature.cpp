//
// Created by Apor Biro on 23.11.2022.
//
#include "Game.h"

Creature::Creature(){}

Creature::Creature(string name, int hp, int maxHp, int strength,vector<Effect*>effect){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
		effects = effect;
}

void Creature::setName(string name){
    this->name = name;
}

void Creature::setHp(int hp){
		this->hp = hp<0?0:(hp>maxHp?maxHp:hp);
}

void Creature::setMaxHp(int maxHp){
    this->maxHp = maxHp;
}

void Creature::setStrength(int strength){
    this->strength = strength;
}

int Creature::affect(FightLog* log){
	for(long unsigned int i=0;i<effects.size();i++){
		log->addLine(name + " has been affected by" + effects[i]->getName());
		if(!effects[i]->affect(this)) return 0;
		if(!effects[i]->getDuration()){
			delete effects[i];
			effects.erase(effects.begin()+i--);
		}
	}
	return 1;
}

void Creature::addEffect(Effect *effect){
	effects.push_back(effect);
}	

void Humanoid::setInventory(Inventory* inventory) {
    this->inventory = inventory;
}

string Creature::getName(){
    return this->name;
}

int Creature::getHp() const{
    return this->hp;
}

int Creature::getMaxHp() const{
    return this->maxHp;
}

int Creature::getStrength() const {
    return this->strength;
}

Inventory* Humanoid::getInventory() const {
    return this->inventory;
}

// Do Creatures have an Inventory? - Ede

bool Creature::attack(Creature* enemy) const{
		return enemy->damage(strength);
}

int Creature::damage(int dmg){
    setHp(hp-dmg);
	return getHp();
}


bool Humanoid::addElementToInventory(Slot* element) {
    return this->inventory->addElement(element);
}

int Humanoid::useElementFromInventoryByIndex(int index, Humanoid * player, Creature * enemy) {
    return this->inventory->useElementByIndex(index, player, enemy);
}

// Humanoid functions implementation

Humanoid::Humanoid(string name, int hp, int maxHp, int strength, vector<Effect*> effect, Armor *armor, Weapon *weapon):Creature(name,hp,maxHp,strength,effect){
    this->armor = armor;
    this->weapon = weapon;
		inventory = new Inventory();
}

Humanoid::Humanoid(string fileName){
	ifstream file(fileName.c_str());
	if(!file.is_open()){exit(-1);}
	file>>hp>>maxHp>>strength;
	string armorName, weaponName;
	file>>armorName;
	if(armorName != "NONE"){
		int armorDefense;
		file >>armorDefense;
		setArmor(new Armor(armorName,armorDefense));
	}
	file>>weaponName;
	if(weaponName != "NONE"){
		int weaponDamage;
		file >>weaponDamage;
		setWeapon(new Weapon(weaponName,weaponDamage));
	}
	inventory = new Inventory();
	string slotName;
	while(file>>slotName){
		string slotType;
		int data1,data2;
		file>> slotType;
		if(slotType == "Armor"){
			file>>data1;
			addElementToInventory(new Armor(slotName,data1));
		}
		else if(slotType == "Weapon"){
			file>>data1;
			addElementToInventory(new Weapon(slotName,data1));
		}
		else if(slotType == "HealingPotion"){
			file>>data1>>data2;
			addElementToInventory(new HealingPotion(slotName,data1,data2));
		}
		else if(slotType == "Fireball"){
			addElementToInventory(new Fireball());
		}
		else if(slotType == "PoisonGas"){
			file>>data1;
			addElementToInventory(new PoisonGas(data1));
		}
		else if(slotType == "Mend"){
			addElementToInventory(new Mend());
		}
	}
	cerr<<"Player Loaded"<<endl;
}

void Humanoid::Save(string fileName){
	ofstream file(fileName.c_str());
	file<<hp<<endl<<maxHp<<endl<<strength<<endl;
	if(armor != NULL)
		file<<armor->getName()<<" "<<armor->getDefense()<<endl;
	else file<<"NONE"<<endl;

	if(weapon != NULL)
		file<<weapon->getName()<<" "<<weapon->getDamage()<<endl;
	else file<<"NONE"<<endl;

	for(Slot *slot: inventory->getElements()){
			file<<slot->getName()<<" ";
		if(typeid(*slot) == typeid(Armor))
			file<<"Armor"<<" "<<((Armor*)slot)->getDefense()<<endl;
		if(typeid(*slot) == typeid(Weapon))
			file<<"Weapon"<<" "<<((Weapon*)slot)->getDamage()<<endl;
		if(typeid(*slot) == typeid(HealingPotion))
			file<<"HealingPotion"<<" "<<((HealingPotion*)slot)->getDuration()<<" "<<((HealingPotion*)slot)->getHp()<<endl;
		if(typeid(*slot) == typeid(Fireball))
			file<<"Fireball"<<" "<<endl;
		if(typeid(*slot) == typeid(PoisonGas))
			file<<"PoisonGas"<<" "<<((PoisonGas*)slot)->getDuration()<<endl;
		if(typeid(*slot) == typeid(Mend))
			file<<"Mend"<<endl;
	}
};

void Humanoid::setArmor(Armor* armor){
    this->armor = armor;
}

void Humanoid::setWeapon(Weapon* weapon){
    this->weapon = weapon;
}

Weapon* Humanoid::getWeapon() const{
    return this->weapon;
}

Armor* Humanoid::getArmor() const{
    return this->armor;
}

bool Humanoid::attack(Creature *enemy) const{
    return enemy->damage((getWeapon()==nullptr)?strength:strength*getWeapon()->getDamage());
}

int Humanoid::damage(int dmg){
	setHp((getArmor()==nullptr)?hp-dmg:hp-max(dmg-armor->getDefense(),0));
    return getHp();
}

int Creature::turn(Creature* enemy,Camera* camera,FightLog* log){
		log->addLine(name +" has attacked");
    return attack(enemy);
}

int Humanoid::turn(Creature* enemy,Camera* camera,FightLog* log){
  int move = getMoveChoice(camera,log);
  switch (move) {
  case 1: 
		log->addLine(name +" has attacked");
		return attack(enemy);
    break;
  case 2:
    int chosen = getInventoryChoice(this,camera); 
		log->addLine(name +" has used "+ getInventory()->getElements()[chosen]->getName());
		return useElementFromInventoryByIndex(chosen,this,enemy);
  }
	return 1;
}
