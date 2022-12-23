#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class Frame{
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int w, h;
	float dx,dy;
public:
	Frame(SDL_Renderer*,string,float ,float );
	float getDx();
	float getDy();
	SDL_Texture* getTexture();
	SDL_Renderer* getRenderer();
	void Draw(int x,int y,int size);
};

enum MoveType{MOVE_IDLE,MOVE_JUMP};

class Move{
	vector<Frame*> Frames;
	MoveType moveType;
	SDL_Renderer* renderer;
	int startTime;
	float animationLength; //Seconds
public:
	vector<Frame*> getFrames();
	MoveType getMoveType();
	Move(SDL_Renderer*, string filename, int startTime, float animationLength);
	void Draw(int x,int y,int size);
	int getStartTime();
	float getAnimationLength();
	void start();
};

class Animation{
	vector <Move*> Movements;
};
