#pragma once

class Entity;

class Camera:public Entity{
	int rangeX,rangeY;
	int blockSize;
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	int getRangeX();
	void update(Entity*,Map*);
	int getRangeY();
	int setRange(int x,int y);
	void getEntityPos(Entity* entity,int &x, int &y);
	int getBlockSize();
	Camera(int posX, int posY);
	SDL_Renderer* getRenderer();
};
