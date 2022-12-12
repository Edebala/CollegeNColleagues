#pragma once

class Entity{
	int posX,posY;
public:
	Entity(int, int);
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	int move(int x,int y);
};

Entity :: Entity
int Entity::getX(){return posX;}
int Entity::getY(){return posY;}
void Entity::setX(int x){posX = x;}
void Entity::setY(int y){posY = y;}
int Entity::moveX(int x,int y){
	posX += x;
	posY += y;
}

