#include "Entity.h"

Entity :: Entity(int x,int y): posX(x),posY(y){}

int Entity::getX(){return posX;}

int Entity::getY(){return posY;}

void Entity::setX(int x){posX = x;}

void Entity::setY(int y){posY = y;}

void Entity::move(int x,int y){
	posX += x;
	posY += y;
}
