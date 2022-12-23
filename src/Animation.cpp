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
	SDL_Rect rect = {x-size/2,y-size/2,size,size};
	SDL_RenderCopy(renderer,texture,0,&rect);
}

Move::Move(SDL_Renderer* renderer,string filename,int start, float length):
	startTime(start),animationLength(length){
	ifstream be(filename);
	string typeStr;
	be >>typeStr;
	if(typeStr == "IDLE")
		moveType = MOVE_IDLE;
	if(typeStr == "JUMP")
		moveType = MOVE_JUMP;
	int deltaX,deltaY;
	string buffer;
	while (be>> buffer){
		be>>deltaX>>deltaY;
		Frames.push_back(new Frame(renderer,buffer,deltaX,deltaY));
	}
}

MoveType Move::getMoveType(){ return moveType;}
int Move::getStartTime(){ return startTime;}
float Move::getAnimationLength(){return animationLength;}

void Move::Draw(int x,int y,int size){
	
}
