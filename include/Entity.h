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

