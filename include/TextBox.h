#pragma once
#include <vector>

class TextLine;
class UIBox;

using namespace std;

class TextBox{
	vector<TextLine*> lines;
	UIBox *box;
public:
	UIBox* getBox();
	void Draw();
};
