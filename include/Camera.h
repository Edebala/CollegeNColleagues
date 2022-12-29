#pragma once

class TextureUnit;
class Entity;

class Camera{
	float posX,posY;
	int rangeX,rangeY;
	int blockSize;
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	float getX();
	float getY();
	void setX(float);
	void setY(float);
	void move(float,float);
	int getRangeX();
	int getRangeY();
	void update(TextureUnit*,Map*,int);
	int setRange(int x,int y);
	void getEntityPos(Entity* entity,int &x, int &y);
	int getBlockSize();
	Camera(float posX, float posY);
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();
};
