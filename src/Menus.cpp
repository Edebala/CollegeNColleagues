#include "Game.h"

int getMoveChoice(Camera* camera,FightLog* log){
	SDL_Renderer* renderer = camera->getRenderer();
	SDL_Window* window = camera->getWindow();
	SDL_Event event;
	
	SDL_Surface *buffer = IMG_Load("Assets/Brick.png");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,buffer);

	UIBox box(300,300,600,600,10);
	box.setTexture(texture);
	box.subDivide(0.5,.3);

	buffer = IMG_Load("Assets/Attack.png");
	texture = SDL_CreateTextureFromSurface(renderer,buffer);
	box.getSubDivisions()[0]->setTexture(texture);
	
	buffer = IMG_Load("Assets/Use.png");
	texture = SDL_CreateTextureFromSurface(renderer,buffer);
	box.getSubDivisions()[1]->setTexture(texture);

	buffer = IMG_Load("Assets/TextBackground.png");
	texture = SDL_CreateTextureFromSurface(renderer,buffer);
	box.getSubDivisions()[2]->setTexture(texture);
	
	UIBox *logBox = box.getSubDivisions()[2];
	logBox->createGrid(1,log->getMaxSize());
  
	TTF_Init();
	TTF_Font *font;
	if(!(font = TTF_OpenFont("Assets/ARCADECLASSIC.TTF",32)))std::cout<<TTF_GetError()<<"\n";
	SDL_Surface *surf;
	SDL_Texture *textTexture;

	SDL_Color White = {255,255,255};

	for(int i=0;i<log->getLines(64).size();i++){
		surf = TTF_RenderText_Solid(font,log->getLines(64)[i].c_str(),White);
		textTexture = SDL_CreateTextureFromSurface(renderer,surf);
		logBox->getSubDivisions()[i]->setTexture(textTexture);
	}

	int mx,my;
	while(event.type != SDL_QUIT){
		SDL_PollEvent(&event);
		SDL_GetMouseState(&mx,&my);
		if(box.getSubDivisions()[0]->isPressed(&event,mx,my))
			return 1;
		if(box.getSubDivisions()[1]->isPressed(&event,mx,my))
			return 2;
		//SDL_RenderClear(renderer);
		box.draw(renderer);
		SDL_RenderPresent(renderer);
		usleep(6000);
	}
};

int getInventoryChoice(Humanoid* player,Camera* camera){
	SDL_Renderer* renderer = camera->getRenderer();
	SDL_Window* window = camera->getWindow();
	SDL_Event event;
	
	SDL_Surface *buffer = IMG_Load("Assets/Brick.png");
	SDL_Texture *bricktxt = SDL_CreateTextureFromSurface(renderer,buffer);

	buffer = IMG_Load("Assets/QuestionMark.png");
	SDL_Texture *questiontxt = SDL_CreateTextureFromSurface(renderer,buffer);

	buffer = IMG_Load("Assets/Sword.png");
	SDL_Texture *swordtxt = SDL_CreateTextureFromSurface(renderer,buffer);

	buffer = IMG_Load("Assets/Armor.png");
	SDL_Texture *armortxt = SDL_CreateTextureFromSurface(renderer,buffer);

	buffer = IMG_Load("Assets/HPPotion.png");
	SDL_Texture *hppottxt = SDL_CreateTextureFromSurface(renderer,buffer);

	buffer = IMG_Load("Assets/FireBall.png");
	SDL_Texture *fireballtxt = SDL_CreateTextureFromSurface(renderer,buffer);

	buffer = IMG_Load("Assets/PoisonGas.png");
	SDL_Texture *poisongastxt = SDL_CreateTextureFromSurface(renderer,buffer);

	buffer = IMG_Load("Assets/Mend.png");
	SDL_Texture *mendtxt = SDL_CreateTextureFromSurface(renderer,buffer);

	UIBox box(300,300,600,600,10);
	box.setTexture(bricktxt);
	box.createGrid(5,4);

	int mx,my;

	for(int i=0;i<player->getInventory()->getElements().size();i++){
		if(typeid(*(player->getInventory()->getElements()[i]))== typeid(Armor))
			box.getSubDivisions()[i]->setTexture(armortxt);
		else if(typeid(*(player->getInventory()->getElements()[i]))== typeid(Weapon))
			box.getSubDivisions()[i]->setTexture(swordtxt);
		else if(typeid(*(player->getInventory()->getElements()[i]))== typeid(HealingPotion))
			box.getSubDivisions()[i]->setTexture(hppottxt);
		else if(typeid(*(player->getInventory()->getElements()[i]))== typeid(Fireball))
			box.getSubDivisions()[i]->setTexture(fireballtxt);
		else if(typeid(*(player->getInventory()->getElements()[i]))== typeid(PoisonGas))
			box.getSubDivisions()[i]->setTexture(poisongastxt);
		else if(typeid(*(player->getInventory()->getElements()[i]))== typeid(Mend))
			box.getSubDivisions()[i]->setTexture(mendtxt);
		else
			box.getSubDivisions()[i]->setTexture(questiontxt);
	}
	while(event.type != SDL_QUIT){
		SDL_PollEvent(&event);
		SDL_GetMouseState(&mx,&my);
		for(int i=0;i<player->getInventory()->getElements().size();i++)
			if(box.getSubDivisions()[i]->isPressed(&event,mx,my))
				return i;
		//SDL_RenderClear(renderer);
		box.draw(renderer);
		SDL_RenderPresent(renderer);
		usleep(6000);
	}
}

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

