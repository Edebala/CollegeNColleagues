#include "Game.h"

TextureUnit:: TextureUnit(Entity* entity,Animation* anim):
	entity(entity),animation(anim){}
Entity* TextureUnit::getEntity(){return entity;}
Animation* TextureUnit::getAnimation(){return animation;}

int TextureUnit::getX(){return entity->getX();}
int TextureUnit::getY(){return entity->getY();}
void TextureUnit::setX(int x){entity->setX(x);}
void TextureUnit::setY(int y){entity->setY(y);}
void TextureUnit::move(int x,int y,int time,Map* map){
	if(entity->tryToMove(x,y,map)){
		if(x>0) animation->setCurrentMove(animation->getMovements()[MOVE_JUMP_RIGHT],time);
		if(x<0) animation->setCurrentMove(animation->getMovements()[MOVE_JUMP_LEFT],time);
		if(y>0) animation->setCurrentMove(animation->getMovements()[MOVE_JUMP_DOWN],time);
		if(y<0) animation->setCurrentMove(animation->getMovements()[MOVE_JUMP_UP],time);
	}
}

void TextureUnit::update(int time){
	if(animation->getCurrentMove()->getStartTime() +
		animation->getCurrentMove()->getAnimationLength() - time <0)
		animation->setCurrentMove(animation->getMovements()[MOVE_IDLE],time);
}

void TextureUnit::Draw(Camera* camera,int time){
	int x, y;
	camera->getEntityPos(entity,x,y);
	animation->getCurrentMove()->Draw(x,y,camera->getBlockSize(),time);
}

bool TextureUnit::isIdle(){
	return (animation->getCurrentMove()->getMoveType()==MOVE_IDLE);
}

