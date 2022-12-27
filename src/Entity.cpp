#include "Game.h"

Entity :: Entity(int x,int y): posX(x),posY(y){}

int Entity::getX(){return posX;}

int Entity::getY(){return posY;}

void Entity::setX(int x){posX = x;}

void Entity::setY(int y){posY = y;}

vector<int> Entity::getWalkableBlocks(){return walkableBlocks;}

bool Entity::canWalkOn(int block){return !(block%2);}

int Entity::tryToMove(int x,int y,Map* map){
	if(canWalkOn(map->getBlock(posX+x,posY+y))){
		move(x,y);
		return 1;
	}
	return 0;
}

void Entity::move(int x,int y){
	posX += x;
	posY += y;
}
