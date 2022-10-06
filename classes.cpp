#include <string>

class Item{
	string name;
};

class Weapon: public Item{
	int damage;
};

class Armor: public Item{
	
};

class Spell{
	int Cast(Creature *caster, Creature* enemy) = 0;
};

class Fireball: public Spell{
	int Cast(Creature *caster, Creature* enemy){
		enemy.damage(5*caster.tool.getMagicAdjust());
	}
}


class Creature{
	int hp,maxHp;
	int strength;
public:
	int attack();
};

class Humanoid: public Creature{
	Armor *armor;
	Tool *weapon;
	int castSpell(Spell*,Enemy*);
	int useItem();
};

class Player: public Humanoid{
	
};
