#include "Game.h"

Teleporter::Teleporter(int posX, int posY, int tx,int ty, string map):Entity(posX,posY){
	targetX = tx;
	targetY = ty;
	targetMapFileName = map;
}

int Teleporter::getTargetX(){return targetX;}
int Teleporter::getTargetY(){return targetY;}
string Teleporter::getMapFileName(){return targetMapFileName;}

void Teleporter::teleport(Entity* creature, MapRenderer* mr){
	mr->setMap(new Map(targetMapFileName));
	creature->setX(targetX);
	creature->setY(targetY);
}
