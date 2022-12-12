#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "items.h"
#include "effects.h"
#include "spells.h"

using namespace std;

class Weapon;
class Armor;
class Effect;
class Spell;

class Creature{
    string name;
    int hp, maxHp;
    int strength;
    vector<Effect> effect;
public:
    Creature(const string& name, int hp, int maxHp, int strength, vector<Effect> effect);
    
	// setters
	void setName(const string& name);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setStrength(int strength);
    void setEffect(vector<Effect> effect);

	// getters
    string getName();
    int getHp() const;
    int getMaxHp() const;
    int getStrength() const;
    vector<Effect> getEffect() const;

	// actions
    virtual bool attack(Creature *enemy) const;
		virtual int damage(int dmg){return (hp-=dmg) < 1;}
};

class Humanoid : public Creature{
    string name;
    int hp, maxHp;
    int strength;
    vector<Effect> effect;
    Armor *armor;
    Weapon *weapon;
public:
    Humanoid(const string& name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Weapon *weapon);

	//setters
    void setArmor(Armor* armor);
    void setWeapon(Weapon* weapon);

	// getters
    Weapon* getWeapon() const;
    Armor* getArmor() const;
    	
	//actions
	bool castSpell(Spell*, Creature*);
	bool attack(Creature *enemy);
	bool useItem(Item*, Creature*);
	bool useItem(Item*, Humanoid*);
	int damage(int dmg){return (hp=max(hp-dmg/armor->getDefense(),0));}
};
