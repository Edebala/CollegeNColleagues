#include "Game.h"

int FightLog::getMaxSize(){return maxSize;}

FightLog::FightLog(int mx):maxSize(mx){}

vector<string> FightLog::getLines(int stringLength){
	vector<string> resultStrings;
	for(int i=0;i<lines.size() && resultStrings.size()<maxSize;i++){
		if(lines[i].length() <= stringLength)
			resultStrings.push_back(lines[i].insert(lines[i].length(),stringLength-lines[i].length(),' '));
		else{
			resultStrings.push_back(lines[i].substr(0,stringLength));
			resultStrings.push_back((lines[i].substr(stringLength,lines[i].length()-stringLength)));
		}
	}
	return resultStrings;
}

void FightLog::addLine(string line){
	lines.emplace(lines.begin(),line);
	if(lines.size() > maxSize)
		lines.pop_back();
}
