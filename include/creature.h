#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "items.h"
#include "effects.h"
#include "spells.h"
//#include "inventory.h"

using namespace std;

class Item;
class Effect;
class Spell;
class Humanoid;
class Armor;
class Weapon;
//class Inventory;

class Throwable;
class HealingPotion;
class WeaponBuffPotion;
class ArmorBuffPotion;
class StrengthenPotion;
class Fireball;
class PoisonGas;
class Debuff;
class Erase;

//using MultiType = variant<Weapon*, Armor*, Throwable*, HealingPotion*, WeaponBuffPotion*, ArmorBuffPotion*, StrengthenPotion*, Fireball*, PoisonGas*, Debuff*, Erase*>;
//This can be 2 types, Item or Spell, No need to specify all children - Ede

class Creature{
protected:
    string name;
    int hp, maxHp;
    int strength;
    bool turn;
    //Inventory * inventory;
public:
    Creature(const string& name, int hp, int maxHp, int strength,vector<Effect> effect);
	// setters
	void setName(const string& name);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setStrength(int strength);
    void setTurn(bool turn);
    //void setInventory(Inventory* inventory);

	// getters
    string getName();
    int getHp() const;
    int getMaxHp() const;
    int getStrength() const;
    bool getTurn() const;
    //Inventory* getInventory() const;

	// actions
    virtual bool attack(Creature *enemy) const;
		virtual int damage(int dmg);
		//bool addElementToInventory(MultiType element);
    //void useElementFromInventoryByIndex(int index, Creature * player, Creature * enemy);
};

class Humanoid : public Creature{
    Armor * armor = nullptr;
    Weapon * weapon = nullptr;
public:
    Humanoid(const string& name, int hp, int maxHp, int strength,vector<Effect>,Armor *armor, Weapon *weapon);

	//setters
    void setArmor(Armor* armor);
    void setWeapon(Weapon* weapon);

	// getters
    Weapon* getWeapon() const;
    Armor* getArmor() const;
    	
	//actions
	bool castSpell(Spell*, Creature*);
	bool attack(Creature *enemy) const;
	bool useItem(Item*, Creature*);
	bool useItem(Item*, Humanoid*);
	int damage(int dmg);
};
