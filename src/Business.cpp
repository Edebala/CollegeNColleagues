#include <iostream>
#include <string>
#include "Game.h"

int fight(Creature *attacker, Creature *enemy,Camera* camera) {
	FightLog *log = new FightLog(9);
	log->addLine("A "+ enemy->getName() + " has appeared");
	bool attackerTurn = true;
	while (1) {
		if (attackerTurn){
			log->addLine(attacker->getName()+" has "+to_string(attacker->getHp())+" hp");
			log->addLine(enemy->getName() + " has " + to_string(enemy->getHp())+" hp");
			if(!attacker->affect(log)){
				return 0;
			}
			if(!attacker->turn(enemy,camera,log)) return 1;
		}
		else{
			if(!enemy->affect(log)){
				return 1;
			}
			if(!enemy->turn(attacker,camera,log)) return 0;
		}
		attackerTurn = !attackerTurn;
	}
	return -1;
}


using namespace std;

void Draw(Camera* camera, MapRenderer* map,TextureUnit* player,int currentTime){
	map->drawMap();
	player->Draw(camera,currentTime);

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

int Explore(TextureUnit* player,Camera* camera){
	MapRenderer* map = new MapRenderer(camera,new Map("Assets/SecondMap.txt"));

	SDL_SetRenderDrawBlendMode(camera->getRenderer(),SDL_BLENDMODE_BLEND);
	TimeManager time;

	SDL_Event event;

	SDL_Surface *buffer = IMG_Load("Assets/SaveGame.png");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(camera->getRenderer(),buffer);

	UIBox box(20,20,400,100,10);
	box.setTexture(texture);

	while (event.type != SDL_QUIT){
		time.tick();
		SDL_RenderClear(camera->getRenderer());
		int mx,my,control = getInput(&event);
		if(player->isIdle()){
			int moveX = -control%2 + (control/2)%2;
			int moveY = (-control/4)%2 +(control/8)%2;
			if(moveX != 0) moveY=0;
			if(player->move(moveX,moveY,time.getCurrentTime(),map->getMap())==2)
				if(rand()%10>6){
					SDL_SetRenderDrawColor(camera->getRenderer(),0,0,0,160);
					SDL_RenderFillRect(camera->getRenderer(),NULL);
					int result = fight(player->getCharacter()->getCreature(),
						new Creature("Dog",30,30,5,vector<Effect*>{}),camera);
					if(result == 0) return 0;
				}
			}
	camera->update(player,map->getMap(),time.getCurrentTime());
		player->update(time.getCurrentTime());
		Draw(camera,map,player,time.getCurrentTime());
		SDL_GetMouseState(&mx,&my);
  	box.draw(camera->getRenderer());
		if(box.isPressed(&event,mx,my))
			((Humanoid*)player->getCharacter()->getCreature())->Save("SaveFile.txt");
  
		SDL_RenderPresent(camera->getRenderer());
	}
}
