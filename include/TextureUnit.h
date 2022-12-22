#pragma once
#include "Entity.h"

class TextureUnit{
	Entity* entity;
	Animation* Animation;
public:
	TextureUnit(Entity*,Animation*);
	Entity* getEntity();
	Animation* getAnimation();
	void Draw(Camera*);
};
