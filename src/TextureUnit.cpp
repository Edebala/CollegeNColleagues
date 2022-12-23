#include "Game.h"

TextureUnit:: TextureUnit(Entity* entity,Animation* anim):
	entity(entity),animation(anim){}
Entity* TextureUnit::getEntity(){return entity;}
Animation* TextureUnit::getAnimation(){return animation;}

int TextureUnit::getX(){return entity->getX();}
int TextureUnit::getY(){return entity->getY();}
void TextureUnit::setX(int x){entity->setX(x);}
void TextureUnit::setY(int y){entity->setY(y);}
void TextureUnit::move(int x,int y,int time){
	entity->move(x,y);
	if(x>0) animation->setCurrentMove(animation->getMovements()[MOVE_JUMP_RIGHT],time);
}

void TextureUnit::update(int time){
	if(animation->getCurrentMove()->getStartTime() +
		animation->getCurrentMove()->getAnimationLength() - time <0)
		animation->setCurrentMove(animation->getMovements()[MOVE_IDLE],time);
}

void TextureUnit::Draw(SDL_Renderer* renderer,Camera* camera,int time){
	int x, y;
	camera->getEntityPos(entity,x,y);
	animation->getCurrentMove()->Draw(x,y,camera->getBlockSize(),time);
}
