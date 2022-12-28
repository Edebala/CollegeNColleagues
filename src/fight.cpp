#include "Game.h"

int fightGUI(Creature *attacker, Creature *enemy,SDL_Renderer* renderer,int width,int height) {
		SDL_Event event;
    bool attackerTurn = true;
    while (1) {
        printf("PlayerHP:%i\nEnemyHP:%i\n\n",attacker->getHp(),enemy->getHp());
        if (attackerTurn){
						if(!attacker->affect()){
							cerr<<"aa"<<endl;
							return 1;
						}
            if(!attacker->turn(enemy)) return 1;
        }
        else{
						if(!enemy->affect()){
							cerr<<"ea"<<endl;
							return 0;
						}
            if(!enemy->turn(attacker)) return 0;
        }
        attackerTurn = !attackerTurn;
    }
    return -1;
}

