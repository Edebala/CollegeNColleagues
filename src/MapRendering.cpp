#include "Game.h"

MapRenderer::MapRenderer(Camera* camera, Map* map):renderer(camera->getRenderer()),camera(camera),map(map){
	SDL_Surface* buffer;
	buffer = IMG_Load("Assets/Grass.png");
	textures.push_back(SDL_CreateTextureFromSurface(renderer,buffer));
	SDL_FreeSurface(buffer);
	buffer = IMG_Load("Assets/Stone.png");
	textures.push_back(SDL_CreateTextureFromSurface(renderer,buffer));
	SDL_FreeSurface(buffer);
	buffer = IMG_Load("Assets/Bush.png");
	textures.push_back(SDL_CreateTextureFromSurface(renderer,buffer));
	SDL_FreeSurface(buffer);
	buffer = IMG_Load("Assets/Brick.png");
	textures.push_back(SDL_CreateTextureFromSurface(renderer,buffer));

}

void MapRenderer::drawMap(){
  for(int i=max(0,camera->getX()-camera->getRangeX()); i<min(map->getWidth(),camera->getX()+camera->getRangeX()+2); i++){
  	for(int j=max(0,camera->getY()-camera->getRangeY()); j<min(map->getHeight(),camera->getY()+camera->getRangeY()+2); j++){
			SDL_Rect rect = {
				(i - camera->getX() + camera->getRangeX())*camera->getBlockSize(),
				(j - camera->getY() + camera->getRangeY())*camera->getBlockSize(),
				camera->getBlockSize(),
				camera->getBlockSize()
			};
			SDL_RenderCopy(renderer,textures[min(3,max(0,map->getBlock(i,j)))],0,&rect);
		}
	}
}

Map* MapRenderer::getMap(){return map;}


