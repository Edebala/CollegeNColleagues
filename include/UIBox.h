#pragma once
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class UIBox{
protected:
	int posX,posY;
	int width,height;
	int padding;
	SDL_Texture* texture;
	SDL_Color* color;
	vector <UIBox*> subDivisions;
public:
	UIBox(int x,int y,int w,int h,int pad);
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int getPadding();
	vector<UIBox*> getSubDivisions();
	void subDivide(float x,float y);
	void draw(SDL_Renderer*);
	void setTexture(SDL_Texture*);
	bool isPressed(SDL_Event*,int,int);
};
