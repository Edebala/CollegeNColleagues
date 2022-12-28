#include "Game.h"

int main(int argc, const char * argv[]) {
	Humanoid * playerCreature = new Humanoid("Player",30,30,5,vector<Effect*>{},NULL,NULL);
	playerCreature->addElementToInventory(new Armor("Diamond Chestplate", 3));
	playerCreature->addElementToInventory(new HealingPotion("HP Poti",7, 5));
	playerCreature->addElementToInventory(new Weapon("Diamond Sword", 4));
	playerCreature->addElementToInventory(new Fireball());
	playerCreature->addElementToInventory(new PoisonGas(4));
	Character *playerEntity = new Character(25,10,playerCreature);

	Explore(playerEntity);
	/*
	SDL_Window* window = SDL_CreateWindow(
	"CollegeNColleges",SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,1200,1200,
	SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(
	window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event event;
	
	SDL_Surface *buffer = IMG_Load("Assets/Grass.png");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,buffer);

	UIBox box(0,0,350,350,10);
	box.setTexture(texture);
	box.subDivide(0.5,0.5);
	box.getSubDivisions()[0]->setTexture(texture);
	box.getSubDivisions()[1]->setTexture(texture);
	box.getSubDivisions()[2]->setTexture(texture);

	int mx,my;
	while(event.type != SDL_QUIT){
		SDL_PollEvent(&event);
		SDL_GetMouseState(&mx,&my);
		if(box.getSubDivisions()[0]->isPressed(&event,mx,my))
			cout<<"Yaay"<<endl;
		SDL_RenderClear(renderer);
		box.draw(renderer);
		SDL_RenderPresent(renderer);
		usleep(10000);
	}
	*/
}
