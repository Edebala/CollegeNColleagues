#include <string>
#include "spells.h"
#include "items.h"
#include "effects.h"

class Item{
	string name;
};

class Spell{
	int Cast(Creature *caster, Creature* enemy) = 0;
};

class Creature{
	int hp,maxHp;
	int strength;
	Team *team;
	vector <Effect>;
public:
	int attack(Creature *enemy);
};

class Humanoid: public Creature{
	Armor *armor;
	Tool *weapon;
	int castSpell(Spell*,Enemy*);
	int useItem();
};

class Player: public Humanoid{
	
};

class Team{
	string name;
	vector <Team> allies;
	vector <Team> enemies;
}
