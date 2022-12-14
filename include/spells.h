#pragma once
#include <cmath>
#include <string>
#include <random>

class Slot;
class Creature;
class Humanoid;

class Spell: public Slot{
    int duration = 0;
public:
    Spell(string name,int duration);
    void setDuration(int duration);
    int getDuration() const;
		bool isSpell();
		virtual int cast(Humanoid*,Creature*)=0;
		int use(Humanoid* user,Creature* enemy){return cast(user,enemy);}
};

// Damaging spells

class Fireball: public Spell{
public:
		Fireball();
    int cast(Humanoid *caster, Creature* enemy);
};

class PoisonGas: public Spell{
public:
    int cast(Humanoid *caster, Creature* enemy);
    PoisonGas(int duration);
};

//Healing Spell

class Mend: public Spell{
public:
	int cast(Humanoid *caster, Creature *enemy);
	Mend();
};

// Debuff spells

class Debuff: public Spell{
    int strength = 0;
    int maxHp = 0;
public:
    Debuff(int duration, int strength, int maxHp);
    int cast(Humanoid *caster, Creature* enemy);
    int getStrength() const;
    int getMaxHp() const;
};

class Erase: public Spell{
public:
    Erase(int duration);
		int cast(Humanoid* caster,Creature* enemy);
};
