#pragma once

class Entity;

class Camera:public Entity{
	int rangeX,rangeY;
	int blockSize = 32;
	SDL_Window* window;
public:
	int getRangeX();
	void update();
	int getRangeY();
	int setRange(int x,int y);
	void getEntityPos(Entity* entity,int &x, int &y);
	int getBlockSize();
	Camera(SDL_Window*,int posX, int posY);
};
