#pragma once

class Entity{
	int posX,posY;
public:
	Entity(int, int);
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	void move(int x,int y);
};

