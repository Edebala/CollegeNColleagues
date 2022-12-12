#include <iostream>
#include "creature.h"
int fight(Humanoid*,Creature*);

int main(int argc, const char * argv[]) {
	Humanoid * player = new Humanoid("Player",30,30,5,vector<Effect>{},NULL,NULL);
	Creature * dog = new Creature("Dog",30,30,5,vector<Effect>{});
	fight(player,dog);
}
