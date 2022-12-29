#pragma once
#include <string>

class TextLine{
	string text;
	SDL_Color* color;
	TTF_Font* font;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
public:
	string getText();
	void Draw(int x,int y,int size);
	TextLine(string text,  SDL_Color*, TTF_Font*);
};
