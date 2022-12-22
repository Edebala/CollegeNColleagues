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

void Frame::Draw(SDL_Renderer *renderer,int x,int y,int size){
	SDL_Rect *rect = new SDL_Rect(x-size/2,y-size/2,size,size);
	SDL_RenderCopy(renderer,texture,0,rect);
}

Move::Move(string filename){
	ifstream be(filename);
	string typeStr;
	be >>typeStr;
	if(typeStr == "IDLE")
		moveType = MoveType.MOVE_IDLE;
	if(typeStr == "JUMP")
		moveType = MoveType.MOVE_JUMP;
	int deltaX,deltaY;
	string buffer;
	while (be>> buffer){
		be>>deltaX>>deltaY;
		Frames.push_back(new Frame(buffer,deltaX,deltaY));
	}
}

MoveType Move::getMoveType(){ return moveType; }

void Move::Draw(int x,int y,int size,int time){
	for(int i=0;i<n;i++)
}
