#include "classes.h"
#include <string>

int fight(Creature *player, Creature *enemy) {
    bool playerTurn = true;
    bool done;
    while (player.getHp() > 0 && enemy.getHp() > 0) {
        if (playerTurn) {
            // move 1 -> fight/attack
            // move 2 -> cast spell
            // move 3 -> use item
            int move = getMove();
            switch (move) {
                case 1:
                    if(attack(player, enemy)) 
                    {
                    	playerTurn = false;
                    }
                    break;
                case 2:
                	int spellType; // = getSpellType;
                	if(spellType == 1)
                	{
                		Fireball* spell;
                		if(spell->Cast(player, enemy))
                		{
                			playerTurn = false;
                		}
                	}
                	else if(spellType == 2)
                	{
                		PoisonGas* spell;
                		if(spell->Cast(player, enemy))
                		{
                			playerTurn = false;
                		}
                	}
                	break;
                case 3:
                	break;
                default: break;    
            }
        } else {

        }
    }
}
bool Creature::attack(Creature* player, Creature *enemy) {
    int enemyHP = enemy->getHp();
    int strength = player->getStrength();
    int weaponDamage = player->getWeaponDmg();
    int armor = enemy->getArmor();
    int damage = 2 * strength * weaponDamage / armor;
    
    int newEnemyHp;
    if(enemyHP > damage)
    {
    	newEnemyHp = enemyHP - damage;	
    }
    else
    {
    	newEnemyHp = 0;
    }
    enemy->setHp(newEnemyHp);
    
    if(enemyHP != enemy->getHp())
    {
    	return true;
    }
    else
    {
    	return false;
    }
}


















