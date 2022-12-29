#include "Game.h"

Move::Move(SDL_Renderer* renderer,string filename,int start, int length):
	startTime(start),animationLength(length){
	ifstream be(filename);
	string typeStr;
	be >>typeStr;
	if(typeStr == "IDLE")
		moveType = MOVE_IDLE;
	if(typeStr == "JUMP")
		moveType = MOVE_JUMP_RIGHT;
	float deltaX,deltaY;
	string buffer;
	while (be>> buffer){
		be>>deltaX>>deltaY;
		frames.push_back(new Frame(renderer,buffer,deltaX,deltaY));
	}
}

MoveType Move::getMoveType(){ return moveType;}
int Move::getStartTime(){ return startTime;}
float Move::getAnimationLength(){return animationLength;}

Frame* Move::getCurrentFrame(int time){
	int fromStart = time - startTime;
	float percentDone = (float)fromStart/animationLength;
	return frames[int(frames.size()*(percentDone>.99?.99:percentDone))];
}

void Move::Draw(int x,int y,int size,int time){
	Frame* frame  = getCurrentFrame(time);
	frame->Draw(x,y,size);
}

Move* Animation::getCurrentMove(){return currentMove;}

void Animation::setCurrentMove(Move *move,int time){
	currentMove = move;
	currentMove->setStartTime(time);
}
vector<Move*> Animation::getMovements(){return Movements;}

Animation::Animation(vector<Move*> moves):Movements(moves){
	currentMove = moves[MOVE_IDLE];
}

void Move::setStartTime(int time){
	startTime = time;
}

