#include "Game.h"

Camera::Camera(int x,int y):Entity(x,y){
	window = SDL_CreateWindow(
	"CollegeNColleges",SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,1200,1200,
	SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(
	window, -1, SDL_RENDERER_ACCELERATED);

	rangeX = 5;
	rangeY = 5;
	blockSize=64;
}

int Camera::getRangeX(){return rangeX;}
int Camera::getRangeY(){return rangeY;}
int Camera::setRange(int x,int y){rangeX = x;rangeY=y;}

void Camera::update(Entity* entity,Map* map){
	int scrWidth,scrHeight;
	setX(min(map->getWidth()-rangeX,max(rangeX,entity->getX())));
	setY(min(map->getHeight()-rangeY,max(rangeY,entity->getY())));
	SDL_GetWindowSize(window,&scrWidth,&scrHeight);
	rangeX = (scrWidth/blockSize+1)/2;
	rangeY = (scrHeight/blockSize+1)/2;
}

int Camera::getBlockSize(){return blockSize;}

void Camera::getEntityPos(Entity* entity, int &x, int &y){
	x = (-posX + entity->getX() + rangeX+0.5)*blockSize;
	y = (-posY + entity->getY() + rangeY+0.5)*blockSize;
};

SDL_Renderer* Camera::getRenderer(){
	return renderer;
}
