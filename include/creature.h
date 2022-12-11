#pragma once
#include <string>
#include <vector>
#include "items.h"
#include "spells.h"

using namespace std;
class Humanoid;
class Spell;
class Item;
class Armor;
class Weapon;

typedef struct{
    Spell * spell = nullptr;
    Item * item = nullptr;
}INV;

class Creature{
    string name;
    int hp, maxHp;
    int strength;
    vector<INV> inventory;
    bool turn;
public:
    Creature(const string& name, int hp, int maxHp, int strength);
	// setters
	void setName(const string& name);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setStrength(int strength);
    void setTurn(bool turn);
    void setInventory(vector<INV> inventory);

	// getters
    string getName();
    int getHp() const;
    int getMaxHp() const;
    int getStrength() const;
    bool getTurn() const;
    vector<INV> getInventory() const;


	// actions
    virtual bool attack(Creature *enemy) const;
    void addToInventory(Spell * newElement);
    void addToInventory(Item * newElement);
};

class Humanoid : public Creature{
    Armor *armor;
    Weapon *weapon;
public:
    Humanoid(const string& name, int hp, int maxHp, int strength, Armor *armor, Weapon *weapon);

	//setters
    void setArmor(Armor* armor);
    void setWeapon(Weapon* weapon);

	// getters
    Weapon* getWeapon() const;
    Armor* getArmor() const;

    //actions
    bool attack(Creature * enemy) const;
};