#include "Game.h"

TextureUnit* loadPlayerAnimation(Camera* camera,Humanoid* hum,int x,int y,bool female){
	Character *playerEntity = new Character(25,10,hum);
	string gender = female?"Female":"Male";
	vector<Move*> moves;
	moves.push_back(new Move(camera->getRenderer(),"Assets/"+gender+"Idle.txt",0,700));
	moves.push_back(new Move(camera->getRenderer(),"Assets/"+gender+"JumpRight.txt",0,200));
	moves.push_back(new Move(camera->getRenderer(),"Assets/"+gender+"JumpLeft.txt",0,200));
	moves.push_back(new Move(camera->getRenderer(),"Assets/"+gender+"JumpUp.txt",0,200));
	moves.push_back(new Move(camera->getRenderer(),"Assets/"+gender+"JumpDown.txt",0,200));
	Animation* animation = new Animation(moves);
	return new TextureUnit(playerEntity,animation);
}

int main(int argc, const char * argv[]) {
	Camera *camera = new Camera(3.0,6.0);
	int Choice = mainMenu(camera);
	TextureUnit *player;
	if (Choice == 2) return 0;
	else if (Choice == 0){
		Choice = characterCreation(camera);
		Humanoid * playerCreature = new Humanoid("Player",30,30,5,vector<Effect*>{},NULL,NULL);
		player = loadPlayerAnimation(camera,playerCreature,25,10,Choice);
		playerCreature->addElementToInventory(new Armor("Diamond_Chestplate", 3));
		playerCreature->addElementToInventory(new HealingPotion("HPPoti",7, 5));
		playerCreature->addElementToInventory(new Weapon("Diamond_Sword", 4));
		playerCreature->addElementToInventory(new Fireball());
		playerCreature->addElementToInventory(new PoisonGas(4));
		playerCreature->addElementToInventory(new Mend());
		Explore(player,camera);
	}
	else if(Choice == 1){
		Humanoid* playerCreature = new Humanoid("SaveFile.txt");
		player = loadPlayerAnimation(camera,playerCreature,25,10,1);
		Explore(player,camera);
	}
}
