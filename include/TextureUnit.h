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
	void Draw(Camera*);
};
