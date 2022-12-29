#include "Game.h"

TimeManager::TimeManager(){
	StartTime = clock();
	time = 0;
	FrameRate = 60;
	T= (double) CLOCKS_PER_SEC/FrameRate;
	BaseTime = StartTime/T;
	delay = 0;
	totalDelay = 0;
}

long TimeManager::getCurrentTime(){
	return currentTime;
}

void TimeManager::tick(){
	if ((totalDelay + clock()) / T < time + BaseTime){
		delay = ((time +BaseTime)* T - (totalDelay+clock()));
		totalDelay += delay;
		usleep(delay);
	}
	time++;
	currentTime = time*T/1000;
}

