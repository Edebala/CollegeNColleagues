#pragma once
#include <string>
#include <vector>
#include "items.h"
#include "effects.h"
#include "spells.h"

using namespace std;
class Humanoid;
class Effect;
class Spell;
class Armor;
class Weapon;

class Creature{
    string name;
    int hp, maxHp;
    int strength;
    vector<Effect> effect;
    vector<Spell*> spells;
    bool turn;
public:
    Creature(const string& name, int hp, int maxHp, int strength, vector<Effect> effect);
	// setters
	void setName(const string& name);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setStrength(int strength);
    void setEffect(vector<Effect> effect);
    void setTurn(bool turn);
    void setSpells(vector<Spell*> spells);

	// getters
    string getName();
    int getHp() const;
    int getMaxHp() const;
    int getStrength() const;
    vector<Effect> getEffect() const;
    bool getTurn() const;
    vector<Spell*> getSpells() const;

	// actions
    virtual bool attack(Creature *enemy) const;
    void addSpell(Spell * spell);
};

class Humanoid : public Creature{
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
    bool attack(Creature * enemy) const;
};