#include "Game.h"

using namespace std;

TextLine::TextLine(string text, SDL_Color* color, TTF_Font* font):
	text(text),color(color),font(font),renderer(renderer)
{
	stringstream ss;
	ss << text;
	SDL_Surface* surf = TTF_RenderText_Solid(font,ss.str().c_str(),*color);
	texture = SDL_CreateTextureFromSurface(renderer,surf);
}

string TextLine::getText(){return text;}
void TextLine::Draw(int x,int y, int size){
	SDL_Rect PrintRect = {x,y,size*text.length()*0.8,size};
	SDL_RenderCopy(renderer,texture,NULL,&PrintRect);
}
