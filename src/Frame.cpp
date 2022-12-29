#include "Game.h"

Frame::Frame(SDL_Renderer* renderer,string textureFile, float dx, float dy):dx(dx),dy(dy),renderer(renderer){
	SDL_Surface* buffer = IMG_Load(textureFile.c_str());
	Uint32 colorkey = SDL_MapRGB(buffer->format,255,255,255);
	SDL_SetColorKey(buffer,SDL_TRUE,colorkey);
	texture = SDL_CreateTextureFromSurface(renderer,buffer);
}

float Frame::getDx(){return dx;}
float Frame::getDy(){return dy;}
SDL_Texture* Frame::getTexture(){return texture;}

void Frame::Draw(int x,int y,int size){
	SDL_Rect rect = {x-size/2+size*dx,y-size/2+size*dy,size,size};
	SDL_RenderCopy(renderer,texture,0,&rect);
}

