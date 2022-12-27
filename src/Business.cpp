#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

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


int fight(Creature *attacker, Creature *enemy) {
    bool attackerTurn = true;
    while (1) {
        printf("PlayerHP:%i\nEnemyHP:%i\n\n",attacker->getHp(),enemy->getHp());
        if (attackerTurn){
						if(!attacker->affect()) return 1;
            if(!attacker->turn(enemy)) return 1;
        }
        else{
						if(!enemy->affect()) return 0;
            if(!enemy->turn(attacker)) return 0;
        }
        attackerTurn = !attackerTurn;
    }
    return -1;
}

void Draw(Camera* camera, MapRenderer* map,TextureUnit* player,int currentTime){
		SDL_RenderClear(camera->getRenderer());
		map->drawMap();
		player->Draw(camera,currentTime);
		SDL_RenderPresent(camera->getRenderer());
};

int getInput(SDL_Event *event){
	const unsigned char* key;
	int control = 0;
	SDL_PollEvent(event);
	key = SDL_GetKeyboardState(0);
	control = (key[SDL_SCANCODE_A]!=0)|
		2*(key[SDL_SCANCODE_D]!=0)|
		4*(key[SDL_SCANCODE_W]!=0)|
		8*(key[SDL_SCANCODE_S]!=0);
	return control;
}

int Explore(Character* playerEntity){
	TextureUnit* player;
	MapRenderer* map;
	Camera* camera;
	init(playerEntity,&player,&map,&camera);

	TimeManager time;

	SDL_Event event;

	while (event.type != SDL_QUIT){
		time.tick();
		int control = getInput(&event);
		if(player->isIdle())
			player->move(-control%2 + (control/2)%2,(-control/4)%2 +(control/8)%2,time.getCurrentTime(),map->getMap());
    camera->update(player,map->getMap(),time.getCurrentTime());
		player->update(time.getCurrentTime());
		Draw(camera,map,player,time.getCurrentTime());
	}
}
