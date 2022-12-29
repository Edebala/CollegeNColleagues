#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int fight(Creature *attacker, Creature *enemy) {
    bool attackerTurn = true;
    while (1) {
        printf("PlayerHP:%i\nEnemyHP:%i\n\n",attacker->getHp(),enemy->getHp());
        if (attackerTurn){
						if(!attacker->affect()) return 1;
            if(!attacker->turn(enemy)) return 1;
        }
        else{
						if(!enemy->affect()) return 0;
            if(!enemy->turn(attacker)) return 0;
        }
        attackerTurn = !attackerTurn;
    }
    return -1;
}

char getInput(){
	char a;
	cin>>a;
	return a;
}

int Explore(Character* player){
	string mapFile="FirstMap.txt";
	vector<Entity*> entities;
	entities.push_back(player);
	Map* map = new Map(mapFile);
	while(true){
		map->printMap(entities);
		char input = getInput();
		player->tryToMove(-1 * (input=='a') + (input =='d'),-1 * (input == 'w') + (input == 's'),map);
		if(map->getBlock(player->getX(),player->getY()) == 2){
			if(rand()%10>7)
				if(fight(player->getCreature(),new Creature("Dog",30,30,5,vector<Effect*>{}))== 0) return 0;
		}
	}
}
