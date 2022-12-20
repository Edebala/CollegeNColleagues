#include "Character.h"

Character::Character(int x,int y,Creature *c):Entity(x,y){
	creature = c;
}

