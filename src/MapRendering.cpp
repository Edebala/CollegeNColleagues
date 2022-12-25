#include "Game.h"

MapRenderer::MapRenderer(SDL_Renderer* renderer, Camera* camera, Map* map):renderer(renderer),camera(camera),map(map){
	SDL_Surface* buffer;
	buffer = IMG_Load("Assets/Grass.png");
	textures.push_back(SDL_CreateTextureFromSurface(renderer,buffer));
	SDL_FreeSurface(buffer);
	buffer = IMG_Load("Assets/Stone.png");
	textures.push_back(SDL_CreateTextureFromSurface(renderer,buffer));
	SDL_FreeSurface(buffer);
	buffer = IMG_Load("Assets/Bush.png");
	textures.push_back(SDL_CreateTextureFromSurface(renderer,buffer));
}

void MapRenderer::drawMap(){
  for(int i=max(0,camera->getX()-camera->getRangeX());i<min(map->getWidth(),camera->getX()+camera->getRangeX());i++){
  	for(int j=max(0,camera->getY()-camera->getRangeY());j<min(map->getHeight(),camera->getY()+camera->getRangeY());j++){
			SDL_Rect rect = {
				(i - camera->getX() + camera->getRangeX()/2)*camera->getBlockSize(),
				(j - camera->getY() + camera->getRangeY()/2)*camera->getBlockSize(),
				camera->getBlockSize(),camera->getBlockSize()};
			SDL_RenderCopy(renderer,textures[min(2,max(0,map->getBlock(i,j)))],0,&rect);
		}
	}
}
