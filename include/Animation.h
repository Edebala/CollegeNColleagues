#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class Frame{
	SDL_Texture* texture;
	int w, h;
	float dx,dy;
public:
	Frame(SDL_Texture*,dx,dy);
	float getDx();
	float getDy();
	void Draw(int x,int y,int size);
}

enum MoveType(MOVE_IDEL,MOVE_JUMP);

class Move{
	vector<Frame> Frames;
	MoveType moveType;
public:
	Move(string filename);
};

class Animation{
	vector <Move*> Movements;
};


