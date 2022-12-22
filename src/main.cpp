#include <iostream>
#include "Game.h"
int fight(Creature*,Creature*);
int Explore(Character*);

int main(int argc, const char * argv[]) {
	Humanoid * player = new Humanoid("Player",30,30,5,vector<Effect*>{},NULL,NULL);
	player->addElementToInventory(new Armor("Diamond Chestplate", 3));
	player->addElementToInventory(new HealingPotion("HP Poti",7, 5));
	player->addElementToInventory(new Weapon("Diamond Sword", 4));
	player->addElementToInventory(new Fireball());
	player->addElementToInventory(new PoisonGas(4));
	//Creature * dog = new Creature("Dog",30,30,5,vector<Effect*>{});
	Character *playerChar = new Character(3,3,player);
	Explore(playerChar);
	//fight(player,dog);
}

