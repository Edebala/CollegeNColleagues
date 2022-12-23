#include "Game.h"

int fight(Creature*,Creature*);
int Explore(Character*);

int main(int argc, const char * argv[]) {
	Humanoid * player = new Humanoid("Player",30,30,5,vector<Effect*>{},NULL,NULL);
	player->addElementToInventory(new Armor("Diamond Chestplate", 3));
	player->addElementToInventory(new HealingPotion("HP Poti",7, 5));
	player->addElementToInventory(new Weapon("Diamond Sword", 4));
	player->addElementToInventory(new Fireball());
	player->addElementToInventory(new PoisonGas(4));
	Character *playerChar = new Character(3,3,player);
	//Explore(playerChar);
	
	SDL_Window *window = SDL_CreateWindow(
	"CollegeNColleges",SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,1200,1200,
	SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(
	window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event event;

	long currentTime,StartTime = clock();
	vector<Move*> moves;
	Move *idle = new Move(renderer,"Assets/PlayerIdle.txt",0,300);
	Move *jump = new Move(renderer,"Assets/PlayerJump.txt",0,100);
	moves.push_back(idle);
	moves.push_back(jump);

	TextureUnit *txtr = new TextureUnit(playerChar,new Animation(moves));

	const unsigned char* key;
	
	Camera *camera = new Camera(window,2,2);
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
		if(txtr->getAnimation()->getCurrentMove()->getMoveType()==MOVE_IDLE){
			SDL_PollEvent(&event);
			key = SDL_GetKeyboardState(0);
			control = (key[SDL_SCANCODE_A]!=0) +
							2*(key[SDL_SCANCODE_D]!=0)+
							4*(key[SDL_SCANCODE_W]!=0)+
							8*(key[SDL_SCANCODE_S]!=0);
			txtr->move(-control%2 + (control/2)%2,(-control/4)%2 +(control/8)%2,currentTime);
		}
		SDL_RenderClear(renderer);
		txtr->Draw(renderer,camera,currentTime);
		txtr->update(currentTime);
		SDL_RenderPresent(renderer);
		usleep(CLOCKS_PER_SEC/60);
	}
}
