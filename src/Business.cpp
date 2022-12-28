#include <iostream>
#include <string>
#include "Game.h"

void init(Character*,TextureUnit**,MapRenderer**,Camera**);
//int fight(Creature*, Creature*);

int fight(Creature *attacker, Creature *enemy) {
    bool attackerTurn = true;
    while (1) {
        printf("PlayerHP:%i\nEnemyHP:%i\n\n",attacker->getHp(),enemy->getHp());
        if (attackerTurn){
						if(!attacker->affect()){
							cerr<<"aa"<<endl;
							return 1;
						}
            if(!attacker->turn(enemy)) return 1;
        }
        else{
						if(!enemy->affect()){
							cerr<<"ea"<<endl;
							return 0;
						}
            if(!enemy->turn(attacker)) return 0;
        }
        attackerTurn = !attackerTurn;
    }
    return -1;
}


using namespace std;

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
	control = (key[SDL_SCANCODE_A]!=0) | 2*(key[SDL_SCANCODE_D]!=0)|
		4*(key[SDL_SCANCODE_W]!=0) | 8*(key[SDL_SCANCODE_S]!=0);
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
			if(player->move(-control%2 + (control/2)%2,(-control/4)%2 +(control/8)%2,time.getCurrentTime(),map->getMap())==2)
				if(rand()%10>6){
					int result = fight(player->getCharacter()->getCreature(),new Creature("Dog",30,30,5,vector<Effect*>{}));
					cerr<<"Result:"<<result<<endl;
					if(result == 0) return 0;

				}
    camera->update(player,map->getMap(),time.getCurrentTime());
		player->update(time.getCurrentTime());
		Draw(camera,map,player,time.getCurrentTime());
	}
}
