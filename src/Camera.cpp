#include "Game.h"

Camera::Camera(SDL_Window* window,int x,int y):window(window),Entity(x,y){
	rangeX = 5;
	rangeY = 5;
	blockSize=64;
}

int Camera::getRangeX(){return rangeX;}
int Camera::getRangeY(){return rangeY;}
int Camera::setRange(int x,int y){rangeX = x;rangeY=y;}

void Camera::update(Entity* entity){
	int scrWidth,scrHeight;
	setX(max(rangeX,entity->getX()));
	setY(max(rangeY,entity->getY()));
	SDL_GetWindowSize(window,&scrWidth,&scrHeight);
	rangeX = (scrWidth/blockSize)/2-1;
	rangeY = (scrHeight/blockSize)/2-1;
	cout<<rangeX<<endl;
}

int Camera::getBlockSize(){return blockSize;}

void Camera::getEntityPos(Entity* entity, int &x, int &y){
	x = (-posX + entity->getX() + rangeX-0.5)*blockSize;
	y = (-posY + entity->getY() + rangeY-0.5)*blockSize;
};
