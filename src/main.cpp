#include "Game.h"

int fight(Creature*,Creature*);
int Explore(Character*);

void init(TextureUnit **player, MapRenderer **map, Camera **camera){
	*camera = new Camera(3,6);
	Humanoid * playerCreature = new Humanoid("Player",30,30,5,vector<Effect*>{},NULL,NULL);
	playerCreature->addElementToInventory(new Armor("Diamond Chestplate", 3));
	playerCreature->addElementToInventory(new HealingPotion("HP Poti",7, 5));
	playerCreature->addElementToInventory(new Weapon("Diamond Sword", 4));
	playerCreature->addElementToInventory(new Fireball());
	playerCreature->addElementToInventory(new PoisonGas(4));
	Character *playerEntity = new Character(3,3,playerCreature);
	
	vector<Move*> moves;
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerIdle.txt",0,300));
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerJumpRight.txt",0,100));
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerJumpLeft.txt",0,100));
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerJumpUp.txt",0,100));
	moves.push_back(new Move((*camera)->getRenderer(),"Assets/PlayerJumpDown.txt",0,100));
	Animation* animation = new Animation(moves);
	*player = new TextureUnit(playerEntity,animation);


	*map = new MapRenderer(*camera,new Map("Assets/SecondMap.txt"));
}

int main(int argc, const char * argv[]) {
	TextureUnit* player;
	MapRenderer* map;
	Camera* camera;
	init(&player,&map,&camera);

	SDL_Event event;

	long currentTime,StartTime = clock();

	const unsigned char* key;
	
	///---------------------------
	int time=0,FrameRate = 60;
	double T =(double) CLOCKS_PER_SEC / FrameRate;
	unsigned BaseTime = clock() / T;
	unsigned delay = 0, totalDelay = 0;
	while (event.type != SDL_QUIT){
	  if ((totalDelay + clock()) / T < time + BaseTime){
		  delay = ((time +BaseTime)* T - (totalDelay+clock()));
		  totalDelay += delay;
		  usleep(delay);
		}
	  time++;
	///-------------This Code Was Reused from older Project
		currentTime = time*T/1000;
		SDL_PollEvent(&event);
		int control = 0;
		if(player->isIdle()){
			SDL_PollEvent(&event);
			key = SDL_GetKeyboardState(0);
			control = (key[SDL_SCANCODE_A]!=0)|
							2*(key[SDL_SCANCODE_D]!=0)|
							4*(key[SDL_SCANCODE_W]!=0)|
							8*(key[SDL_SCANCODE_S]!=0);
			player->move(-control%2 + (control/2)%2,(-control/4)%2 +(control/8)%2,currentTime,map->getMap());
		}
		SDL_RenderClear(camera->getRenderer());
    camera->update(player->getEntity(),map->getMap());
		map->drawMap();
		player->Draw(camera,currentTime);
		player->update(currentTime);
		SDL_RenderPresent(camera->getRenderer());
		usleep(CLOCKS_PER_SEC/60);
	}
}
