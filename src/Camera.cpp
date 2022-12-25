#include "Game.h"

Camera::Camera(SDL_Window* window,int x,int y):window(window),Entity(x,y){
	rangeX = 5;
	rangeY = 5;
	blockSize=64;
}

int Camera::getRangeX(){return rangeX;}
int Camera::getRangeY(){return rangeY;}
int Camera::setRange(int x,int y){rangeX = x;rangeY=y;}

void Camera::update(){
	int scrWidth,scrHeight;
	SDL_GetWindowSize(window,&scrWidth,&scrHeight);
	rangeX = (scrWidth/blockSize)/2+1;
	rangeY = (scrHeight/blockSize)/2+1;
}

int Camera::getBlockSize(){return blockSize;}

void Camera::getEntityPos(Entity* entity, int &x, int &y){
	x = (-posX + entity->getX() + rangeX+0.5)*blockSize;
	y = (-posY + entity->getY() + rangeY+0.5)*blockSize;
};
