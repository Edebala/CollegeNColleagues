#include "../include/Business.h"

int fight(Creature *player, Creature *enemy) {
	bool roundNumber = 1;
	int playersChoise = 1;
	bool dead = false;

	while(true){
		// humaniod's turn

		// get players move
		switch(playersChoise){
			case 1:
				if(player.attack(enemy))
					dead = true;
				break;
			case 2:
				//spell
				break;
			case 3:
				//use item ???
				break;
		}

		if(dead)
			break;

		// creature/enemy's turn
		if(enemy.attack(player))
			dead = true;

		if(dead)
			break;

		++roundNumber;
	}
}

int getPlayersMoove()
{
    int move = 1;

    return move;
}
