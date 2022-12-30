#include "Game.h"

int mainMenu(Camera* camera){

	SDL_Renderer* renderer = camera->getRenderer();
	SDL_Window* window = camera->getWindow();
	SDL_Event event;
	
	SDL_Surface *buffer;

	UIBox box(300,300,550,450,10);
	box.createGrid(3,3);
	box.getSubDivisions()[4]->createGrid(1,3);

	UIBox* menu = box.getSubDivisions()[4];

	buffer = IMG_Load("Assets/Grass.png");
	SDL_Texture* background = SDL_CreateTextureFromSurface(renderer,buffer);
	box.setTexture(background);
	
	buffer = IMG_Load("Assets/NewGame.png");
	SDL_Texture* newGame = SDL_CreateTextureFromSurface(renderer,buffer);
	menu->getSubDivisions()[0]->setTexture(newGame);

	ifstream file("SaveFile.txt");
	bool saveFileExists = false;
	if(file.is_open()){
		buffer = IMG_Load("Assets/LoadGame.png");
		SDL_Texture* loadGame = SDL_CreateTextureFromSurface(renderer,buffer);
		menu->getSubDivisions()[1]->setTexture(loadGame);
		saveFileExists = true;
	}

	buffer = IMG_Load("Assets/Quit.png");
	SDL_Texture* quit = SDL_CreateTextureFromSurface(renderer,buffer);
	menu->getSubDivisions()[2]->setTexture(quit);

	int mx,my;
	while(event.type != SDL_QUIT){
		SDL_RenderPresent(renderer);
		SDL_PollEvent(&event);
		SDL_GetMouseState(&mx,&my);
		for(int i=0;i<menu->getSubDivisions().size();i++)
			if(menu->getSubDivisions()[i]->isPressed(&event,mx,my)){
				if(i == 1 && !saveFileExists)i++;
				return i;
			}
		box.draw(renderer);
		SDL_RenderPresent(renderer);
		usleep(6000);
	}
}

int characterCreation(Camera* camera){

	SDL_Renderer* renderer = camera->getRenderer();
	SDL_Window* window = camera->getWindow();
	SDL_Event event;
	
	SDL_Surface *buffer;

	UIBox box(200,300,750,450,10);
	box.createGrid(5,3);

	buffer = IMG_Load("Assets/Grass.png");
	SDL_Texture* background = SDL_CreateTextureFromSurface(renderer,buffer);
	box.setTexture(background);
	
	buffer = IMG_Load("Assets/Male.png");
	SDL_Texture* male = SDL_CreateTextureFromSurface(renderer,buffer);
	box.getSubDivisions()[6]->setTexture(male);

	buffer = IMG_Load("Assets/Female.png");
	SDL_Texture* female = SDL_CreateTextureFromSurface(renderer,buffer);
	box.getSubDivisions()[8]->setTexture(female);

	int mx,my;
	while(event.type != SDL_QUIT){
		SDL_RenderPresent(renderer);
		SDL_PollEvent(&event);
		SDL_GetMouseState(&mx,&my);
		if(box.getSubDivisions()[6]->isPressed(&event,mx,my))
			return 0;
		if(box.getSubDivisions()[8]->isPressed(&event,mx,my))
			return 1;
		box.draw(renderer);
		SDL_RenderPresent(renderer);
		usleep(6000);
	}
}

TextureUnit* loadPlayerAnimation(Camera* camera,Humanoid* hum,int x,int y,bool female){
		Character *playerEntity = new Character(25,10,hum);
		if(!female){
			vector<Move*> moves;
			moves.push_back(new Move(camera->getRenderer(),"Assets/MaleIdle.txt",0,700));
			moves.push_back(new Move(camera->getRenderer(),"Assets/MaleJumpRight.txt",0,200));
			moves.push_back(new Move(camera->getRenderer(),"Assets/MaleJumpLeft.txt",0,200));
			moves.push_back(new Move(camera->getRenderer(),"Assets/MaleJumpUp.txt",0,200));
			moves.push_back(new Move(camera->getRenderer(),"Assets/MaleJumpDown.txt",0,200));
			Animation* animation = new Animation(moves);
			return new TextureUnit(playerEntity,animation);
		}else{
			vector<Move*> moves;
			moves.push_back(new Move(camera->getRenderer(),"Assets/FemaleIdle.txt",0,700));
			moves.push_back(new Move(camera->getRenderer(),"Assets/FemaleJumpRight.txt",0,200));
			moves.push_back(new Move(camera->getRenderer(),"Assets/FemaleJumpLeft.txt",0,200));
			moves.push_back(new Move(camera->getRenderer(),"Assets/FemaleJumpUp.txt",0,200));
			moves.push_back(new Move(camera->getRenderer(),"Assets/FemaleJumpDown.txt",0,200));
			Animation* animation = new Animation(moves);
			return new TextureUnit(playerEntity,animation);
		}
}

int main(int argc, const char * argv[]) {
	Camera *camera = new Camera(3.0,6.0);
	int Choice = mainMenu(camera);
	TextureUnit *player;
	if (Choice == 2) return 0;
	if (Choice == 0){
		Choice = characterCreation(camera);
		Humanoid * playerCreature = new Humanoid("Player",30,30,5,vector<Effect*>{},NULL,NULL);
		player = loadPlayerAnimation(camera,playerCreature,25,10,Choice);
		playerCreature->addElementToInventory(new Armor("Diamond Chestplate", 3));
		playerCreature->addElementToInventory(new HealingPotion("HP Poti",7, 5));
		playerCreature->addElementToInventory(new Weapon("Diamond Sword", 4));
		playerCreature->addElementToInventory(new Fireball());
		playerCreature->addElementToInventory(new PoisonGas(4));
		playerCreature->addElementToInventory(new Mend(7));
		Explore(player,camera);
	}
	if(Choice == 1){
		
	}
}
