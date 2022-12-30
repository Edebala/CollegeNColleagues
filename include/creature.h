#pragma once
#include <string>
#include <vector>
#include <variant>
#include <algorithm>
#include "Game.h"
#include "effects.h"
#include "inventory.h"

using namespace std;

class Slot;
class Item;
class Effect;
class Spell;
class Humanoid;
class Armor;
class Weapon;
class Inventory;

class Throwable;
class HealingPotion;
class WeaponBuffPotion;
class ArmorBuffPotion;
class StrengthenPotion;
class Fireball;
class PoisonGas;
class Debuff;
class Erase;
class Camera;
class FightLog;

class Creature{
protected:
    string name;
    int hp, maxHp;
    int strength;
		vector<Effect*> effects;
    //Inventory * inventory;
public:
    Creature(const string& name, int hp, int maxHp, int strength,vector<Effect*> effect);
    Creature();
	// setters
	void setName(const string& name);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setStrength(int strength);
    //void setInventory(Inventory* inventory);

	// getters
    string getName();
    int getHp() const;
    int getMaxHp() const;
    int getStrength() const;
	// actions
    virtual bool attack(Creature *enemy) const;
	  virtual int damage(int dmg);
    virtual int turn(Creature *enemy,Camera*,FightLog*);
		virtual bool addElementToInventory(Slot*  element){return false;}
		void addEffect(Effect*);
		int affect(FightLog*);
};

class Humanoid : public Creature{
    Armor * armor = nullptr;
    Weapon * weapon = nullptr;
	Inventory * inventory;
public:
    Humanoid(const string& name, int hp, int maxHp, int strength,vector<Effect*>,Armor *armor, Weapon *weapon);
    Humanoid(string fileName);

	//setters
  void setArmor(Armor* armor);
  void setWeapon(Weapon* weapon);
	void setInventory(Inventory* inventory);
	Inventory* getInventory() const;

	// getters
    Weapon* getWeapon() const;
    Armor* getArmor() const;
	//actions
	bool attack(Creature *enemy) const;
	bool use(Slot*, Creature*);
	int damage(int dmg);
  virtual int turn(Creature *enemy,Camera*,FightLog*);
	bool addElementToInventory(Slot* element);
  int useElementFromInventoryByIndex(int index, Humanoid * player, Creature * enemy);
};
