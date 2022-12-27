#include "Game.h"

int main(int argc, const char * argv[]) {
	Humanoid * playerCreature = new Humanoid("Player",30,30,5,vector<Effect*>{},NULL,NULL);
	playerCreature->addElementToInventory(new Armor("Diamond Chestplate", 3));
	playerCreature->addElementToInventory(new HealingPotion("HP Poti",7, 5));
	playerCreature->addElementToInventory(new Weapon("Diamond Sword", 4));
	playerCreature->addElementToInventory(new Fireball());
	playerCreature->addElementToInventory(new PoisonGas(4));
	Character *playerEntity = new Character(3,3,playerCreature);

	Explore(playerEntity);
}
