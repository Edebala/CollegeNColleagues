#include <string>
#include "spells.h"
#include "items.h"
#include "effects.h"
#include <string>
#include <vector>



class Item{
	std::string name;
};

class Spell{
	int Cast(Creature *caster, Creature* enemy) = 0;
};

class Creature{
	int hp,maxHp;
	int strength; // [0, 10]
	Team *team;
	vector <Effect>;
public:
	int attack(Creature *enemy);
};

class Humanoid: public Creature{
	Armor *armor;
	Weapon *weapon;
	int castSpell(Spell*,Enemy*);
	int useItem();
};

class Player: public Humanoid{
	
};

class Team{
	std::string name;
	std::vector<Team> allies;
	std::vector<Team> enemies;
}
