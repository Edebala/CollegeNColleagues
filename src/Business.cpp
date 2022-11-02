#include "classes.h"

int humanoid.turn(Creature *enemy)
{
	//TODO:SHOW CHOICES
	char choice = getChoice(), answer;
	bool yourTurn = true;
	while(yourTurn)
	switch(choice)
    {
		//FIGHT
		case 'f':
			yourTurn = false;
			attack(enemy);
		break;
		//USE ITEM
		case 'i':
			Item* chosenItem = chooseItem();
			if(answer = chosenItem.use(player,enemy)>0)
				yourTurn = false;
		break;
		//CAST SPELL
		case 's':
			yourTurn = false;
		break;
	}
}

int creature.turn(Creature *enemy){
	attack(enemy);
}

int Player::useItem(Item *item,Enemy *enemy);
int Player::castSpell(Spell* spell,Enemy *enemy);
int Player::attack(Enemy* enemy);

// strength
int Creature::attack(Creature *enemy) {
    if(enemy.getHp() > 0)
    {
        float damage = ;

    }
}

int fight(Creature *player, Creature *enemy){
	while(everyoneLives){
		int turn;
		if(turn == player->turn(enemy))
			return player->turn;
		if(enemy->turn(player))
			return 2;
	}
	return 0;
}

