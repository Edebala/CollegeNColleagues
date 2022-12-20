#include <iostream>
#include "creature.h"
int fight(Creature*,Creature*);
int Explore(Character*);

int main(int argc, const char * argv[]) {
	Armor* armor = new Armor("Diamond Chestplate", 3);
	Humanoid * player = new Humanoid("Player",30,30,5,vector<Effect>{},armor,NULL);
	Creature * dog = new Creature("Dog",30,30,5,vector<Effect>{});
	Character *playerChar = new Character(3,3,player);
	Explore(playerChar);
	fight(player,dog);
}

