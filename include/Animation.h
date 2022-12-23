#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class Frame;

enum MoveType{MOVE_IDLE,MOVE_JUMP_RIGHT,MOVE_JUMP_UP,MOVE_JUMP_DOWN};

class Move{
	vector<Frame*> frames;
	MoveType moveType;
	SDL_Renderer* renderer;
	int startTime, animationLength; //Seconds
public:
	vector<Frame*> getFrames();
	MoveType getMoveType();
	Move(SDL_Renderer*, string file, int sTime, int moveLen);
	void Draw(int x,int y,int size,int time);
	int getStartTime();
	void setStartTime(int);
	float getAnimationLength();
	void start();
};

class Animation{
	Move* currentMove;
	vector <Move*> Movements;
public:
	Animation(vector<Move*>);
	void setCurrentMove(Move*,int time);
	Move *getCurrentMove();
	vector <Move*> getMovements();
};
