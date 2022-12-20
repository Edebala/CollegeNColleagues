#include "Map.h"

int Map::getWidth(){return width;}
int Map::getHeight(){return height;}
int Map::getBlock(int x,int y){
	return (width<x||height<y)?-1:blocks[y*height+x];
}
int Map::setBlock(int x,int y, int block){
	return (width<x||height<y)?-1:blocks[y*height+x]=block;
}
int Map::loadFromFile(string fileName){
  ifstream be(fileName);
  if(be>>height) return 0;
  if(be>>width) return 0;
  blocks = new int(width*height);
  for(int i=0;i<height;i++)
    for(int j=0;i<width;j++)
      if(!be>>blocks[i*width+j]) return 0;
  return 1;
}

Map::Map(string filename){
	loadFromFile(filename);
}

Map::Map(int n,int m,int *blocks){
	width = n;
	height = m;
  blocks = new int(width*height);
  for(int i=0;i<height;i++)
    for(int j=0;j<width;j++)
      this->blocks[i*width+j] = blocks[i*width+j];
}

Map* Map::getSubMap(int x,int y, int m,int n){
	
}
