#include "Game.h"

void init(Character* playerEntity,TextureUnit **player, MapRenderer **map, Camera **camera){
	*camera = new Camera(3.0,6.0);
	
	vector<Move*> moves;
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerIdle.txt",0,700));
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerJumpRight.txt",0,200));
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerJumpLeft.txt",0,200));
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerJumpUp.txt",0,200));
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerJumpDown.txt",0,200));
	Animation* animation = new Animation(moves);
	*player = new TextureUnit(playerEntity,animation);

	*map = new MapRenderer(*camera,new Map("Assets/SecondMap.txt"));
}

