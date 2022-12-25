#include "MapRendering.h"
oid MapRendering::drawMap(){
  Camera->getX();
  Map* smallMap = getSubMap(camera->getX()-camera->getRangeX(),camera->getY()-camera->getRangeY(),2*camera->getRangeX()+1,2*camera->getRangeY()+1);
  for(int i=0;i<smallMap->getHeight();i++)
    for(int j=0;j<smallMap->getWidth();j++)
}