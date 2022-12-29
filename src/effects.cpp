#include "Game.h"

Effect::Effect(const string& name, int duration) {
    this->name = name;
    this->duration = duration;
}

int Effect::affect(Creature* target){
	duration--;
	return target->getHp();
}

int Effect::getDuration(){return duration;}

Regeneration::Regeneration(int duration,int value):Effect("Regeneration",duration){
	this->value = value;
}

int Regeneration::affect(Creature* target){
	target->setHp(target->getHp()+ value);
	return Effect::affect(target);
}

void Regeneration::print(){
	cout<<name<<":"<<" Gives "<<value<<" hp for "<<duration<<" rounds\n";
}

string Effect::getName(){return name;}
