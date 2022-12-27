#include "Game.h"

Camera::Camera(float x,float y):posX(x),posY(y){
	window = SDL_CreateWindow(
	"CollegeNColleges",SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,1200,1200,
	SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(
	window, -1, SDL_RENDERER_ACCELERATED);

	rangeX = 5;
	rangeY = 5;
	blockSize=48;
}

float Camera::getX(){return posX;}
float Camera::getY(){return posY;}
void Camera::setX(float x){posX = x;}
void Camera::setY(float y){posY = y;}
void Camera::move(float x,float y){
	posX+=x;
	posY+=y;
}
int Camera::getRangeX(){return rangeX;}
int Camera::getRangeY(){return rangeY;}
int Camera::setRange(int x,int y){rangeX = x;rangeY=y;}

void Camera::update(TextureUnit* txtr,Map* map,int time){
	int scrWidth,scrHeight;
	float targetX = min(map->getWidth()-rangeX,max(rangeX,txtr->getX()));
	float targetY = min(map->getHeight()-rangeY,max(rangeY,txtr->getY()));
	move((targetX-posX)/16,(targetY-posY)/32);
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
