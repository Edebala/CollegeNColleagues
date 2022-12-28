#pragma once

class Animation;
class Camera;
class Map;

class TextureUnit{
	Entity* entity;
	Animation* animation;
public:
	TextureUnit(Entity*,Animation*);
	Character* getCharacter();
	Animation* getAnimation();
	void Draw(Camera*,int time);
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	int move(int x,int y,int time,Map*);
	void update(int time);
	bool isIdle();
};
