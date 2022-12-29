#include "Game.h"

void init(MapRenderer **map, Camera *camera){
	*map = new MapRenderer(camera,new Map("Assets/SecondMap.txt"));
}

