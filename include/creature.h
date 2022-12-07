#pragma once
#include <string>
#include <vector>
#include "items.h"
#include "effects.h"

using namespace std;

class Humanoid;
class Weapon;
class Armor;

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
    virtual bool attack(Humanoid *enemy) const;
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
};
