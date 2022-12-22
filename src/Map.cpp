#include "Game.h"

int Map::getWidth(){return width;}
int Map::getHeight(){return height;}
int Map::getBlock(int x,int y){
	return (width<x||height<y)?-1:blocks[y][x];
}
int Map::setBlock(int x,int y, int block){
	return (width<x||height<y)?-1:blocks[y][x]=block;
}
int Map::loadFromFile(string fileName){
  ifstream be(fileName);
  if(!(be>>height)) return 1;
  if(!(be>>width)) return 2;
  blocks = new int*[height];
  for(int i=0;i<height;i++){
		blocks[i] = new int[width];
    for(int j=0;j<width;j++)
      if(!(be>>blocks[i][j])) return 3;
	}
  return 0;
}

Map::Map(string filename){
	loadFromFile(filename);
}

Map::Map(int n,int m,int **blocks){
	width = n;
	height = m;
  blocks = new int*[height];
  for(int i=0;i<height;i++){
  	blocks[i] = new int[width];
    for(int j=0;j<width;j++)
      this->blocks[i][j] = blocks[i][j];
	}
}

Map* Map::getSubMap(int x,int y, int m,int n){
	int** subMap = new int*[m];
	for(int i=0;i<m;i++){
		subMap[i] = new int[n];
		for(int j=0;j<n;j++)
			subMap[i][j] = blocks[x+i][y+j];
	}
	return new Map(m,n,subMap);
}

void Map::printMap(vector <Entity*> entities){
	bool EntityDrawn = false;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			bool EntityDrawn = false;
			for(int k=0;k<entities.size();k++)
				if(entities[k]->getX() == j && entities[k]->getY() == i){
					printf("X");
					EntityDrawn = true;
					break;
				}
			if(!EntityDrawn)
				printf("%c",(getBlock(j,i)==0)?' ':'a'+getBlock(j,i));
		}
		printf("\n");
	}
	printf("\n");
}
