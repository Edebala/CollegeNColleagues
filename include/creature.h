#pragma once
#include <string>
#include <vector>
#include "items.h"
#include "effects.h"

using namespace std;
class Humanoid;
class Effect;

class Creature{
    string name;
    int hp, maxHp;
    int strength;
    vector<Effect> effect;
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

	// getters
    string getName();
    int getHp() const;
    int getMaxHp() const;
    int getStrength() const;
    vector<Effect> getEffect() const;
    bool getTurn() const;

	// actions
    bool attack(Humanoid *enemy) const;
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
	//bool castSpell(Spell*, Creature*);
	bool attack(Creature *enemy) const;
	bool useItem(Item*, Creature*);
<<<<<<< HEAD
};
=======
	bool useItem(Item*, Humanoid*);
};
>>>>>>> a5f7f85e74edf472939269c6ab3c3758338b9755
