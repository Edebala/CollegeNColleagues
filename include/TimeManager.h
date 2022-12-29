#pragma once

class TimeManager{
	int time,FrameRate;
	double T;
	unsigned BaseTime;
	unsigned delay, totalDelay;
	long currentTime,StartTime;
public:
	TimeManager();
	void tick();
	long getCurrentTime();
};

