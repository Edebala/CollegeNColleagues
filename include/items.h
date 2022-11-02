class Item{};

class Weapon: public Item{
	int damage;
public:
    int getWeaponDmg();
};

class Armor: public Item{
	int defense;
};
