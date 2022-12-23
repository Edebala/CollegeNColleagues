#pragma once

class Animation;
class Camera;

class TextureUnit{
	Entity* entity;
	Animation* animation;
public:
	TextureUnit(Entity*,Animation*);
	Entity* getEntity();
	Animation* getAnimation();
	void Draw(SDL_Renderer*,Camera*,int time);
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	void move(int x,int y,int time);
	void update(int time);
};
