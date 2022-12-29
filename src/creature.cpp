//
// Created by Apor Biro on 23.11.2022.
//
#include "Game.h"

Creature::Creature(const string& name, int hp, int maxHp, int strength,vector<Effect*>effect){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
		effects = effect;
}

void Creature::setName(const string& name){
    this->name = name;
}

void Creature::setHp(int hp){
		this->hp = hp<0?0:(hp>maxHp?maxHp:hp);
}

void Creature::setMaxHp(int maxHp){
    this->maxHp = maxHp;
}

void Creature::setStrength(int strength){
    this->strength = strength;
}

int Creature::affect(){
	for(long unsigned int i=0;i<effects.size();i++){
		if(!effects[i]->affect(this)) return 0;
		if(!effects[i]->getDuration()){
			delete effects[i];
			effects.erase(effects.begin()+i--);
		}
	}
	return 1;
}

void Creature::addEffect(Effect *effect){
	effects.push_back(effect);
}	

void Humanoid::setInventory(Inventory* inventory) {
    this->inventory = inventory;
}

string Creature::getName(){
    return this->name;
}

int Creature::getHp() const{
    return this->hp;
}

int Creature::getMaxHp() const{
    return this->maxHp;
}

int Creature::getStrength() const {
    return this->strength;
}

Inventory* Humanoid::getInventory() const {
    return this->inventory;
}

// Do Creatures have an Inventory? - Ede

bool Creature::attack(Creature* enemy) const{
		return enemy->damage(strength);
}

int Creature::damage(int dmg){
    setHp(hp-dmg);
	return getHp();
}


bool Humanoid::addElementToInventory(Slot* element) {
    return this->inventory->addElement(element);
}

int Humanoid::useElementFromInventoryByIndex(int index, Humanoid * player, Creature * enemy) {
    return this->inventory->useElementByIndex(index, player, enemy);
}

// Humanoid functions implementation

Humanoid::Humanoid(const string& name, int hp, int maxHp, int strength, vector<Effect*> effect, Armor *armor, Weapon *weapon):Creature(name,hp,maxHp,strength,effect){
    this->armor = armor;
    this->weapon = weapon;
		inventory = new Inventory();
}

void Humanoid::setArmor(Armor* armor){
    this->armor = armor;
}

void Humanoid::setWeapon(Weapon* weapon){
    this->weapon = weapon;
}

Weapon* Humanoid::getWeapon() const{
    return this->weapon;
}

Armor* Humanoid::getArmor() const{
    return this->armor;
}

bool Humanoid::attack(Creature *enemy) const{
    return enemy->damage((getWeapon()==nullptr)?strength:strength*getWeapon()->getDamage());
}

int Humanoid::damage(int dmg){
	setHp((getArmor()==nullptr)?hp-dmg:hp-max(dmg-armor->getDefense(),0));
    return getHp();
}

int Creature::turn(Creature* enemy,Camera* camera){
    return attack(enemy);
}


int getMoveChoice(Camera* camera){
	SDL_Renderer* renderer = camera->getRenderer();
	SDL_Window* window = camera->getWindow();
	SDL_Event event;
	
	SDL_Surface *buffer = IMG_Load("Assets/Brick.png");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,buffer);

	UIBox box(300,300,350,350,10);
	box.setTexture(texture);
	box.subDivide(0.5,.3);

	buffer = IMG_Load("Assets/Attack.png");
	texture = SDL_CreateTextureFromSurface(renderer,buffer);
	box.getSubDivisions()[0]->setTexture(texture);
	
	buffer = IMG_Load("Assets/Use.png");
	texture = SDL_CreateTextureFromSurface(renderer,buffer);
	box.getSubDivisions()[1]->setTexture(texture);

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
		usleep(10000);
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

	UIBox box(300,300,350,350,10);
	box.setTexture(bricktxt);
	box.createGrid(5,4);

	int mx,my;

	for(int i=0;i<player->getInventory()->getElements().size();i++){
		if(typeid(*(player->getInventory()->getElements()[i]))== typeid(Armor))
			box.getSubDivisions()[i]->setTexture(armortxt);
		else if(typeid(*(player->getInventory()->getElements()[i]))== typeid(Weapon))
			box.getSubDivisions()[i]->setTexture(swordtxt);
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
		usleep(10000);
	}
};

int Humanoid::turn(Creature* enemy,Camera* camera){
	cerr<<"WhatToDo\n";
	cerr<<"1:Attack\n";
	cerr<<"2:Use Something\n";
  int move = getMoveChoice(camera);
  switch (move) {
  case 1: return attack(enemy);
    break;
  case 2:
		if(getInventory()->getElements().size()==0) break;
		getInventory()->printElements();
    int chosen = getInventoryChoice(this,camera); 
		return useElementFromInventoryByIndex(chosen,this,enemy);
  }
	return 1;
}
