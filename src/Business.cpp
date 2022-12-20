#include <cstdio>
#include "Game.h"

int fight(Creature *attacker, Creature *enemy) {
    bool attackerTurn = true;
    while (1) {
        printf("PlayerHP:%i\nEnemyHP:%i\n\n",attacker->getHp(),enemy->getHp());
        if (!attackerTurn){
            if(!attacker->turn(enemy)) return 1;
        }
        else{
            if(!enemy->turn(attacker)) return 0;
        }
        attackerTurn = !attackerTurn;
    }
    return -1;
}
