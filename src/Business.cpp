#include <cstdio>
#include <string>
#include "creature.h"
#include "spells.h"

int fight(Humanoid *player, Creature *enemy) {
    bool playerTurn = true;
    while (player->getHp() > 0 && enemy->getHp() > 0) {
				printf("PlayerHP:%i\nEnemyHP:%i\n\n",player->getHp(),enemy->getHp());
        if (playerTurn) {
            // move 1 -> fight/attack
            // move 2 -> cast spell
            // move 3 -> use item
            int move = 1;
            switch (move) {
                case 1:
                    if(player->attack(enemy)) 
                    {
                    	playerTurn = false;
                    }
                    break;
                case 2:
                	int spellType = 1; // = getSpellType;
                	if(spellType == 1)
                	{
                		Spell* spell = new Fireball();
                		if(spell->Cast(player, enemy))
                		{
                			playerTurn = false;
                		}
                	}
                	else if(spellType == 2)
                	{
                		Spell* spell = new PoisonGas(5);
                		if(spell->Cast(player, enemy))
                		{
                			playerTurn = false;
                		}
                	}
                	break;
            }
        } else {

        }
    }
		return -1;
}
