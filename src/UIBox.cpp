#include "Game.h"

UIBox::UIBox(int x,int y,int w,int h,int pad):
	posX(x),posY(y),width(w),height(h),padding(pad){texture = NULL;}

void UIBox::subDivide(float x,float y){
	if((x>1 || y>1) || (x==1 && y==1) || (x<=0||y<=0)){
		cerr<<"Invalid UIBox Subdivide"<<endl;
		exit(-1);
	}
	int newX=posX+padding+(width-2*padding)*x,
			newY=posY+padding+(height-2*padding)*y;
	if(y==1){
		subDivisions.push_back(
			new UIBox(posX+padding,posY+padding,(width-2*padding)*x,height-2*padding,padding));
		subDivisions.push_back(
			new UIBox(newX,posY+padding,(width-2*padding)*(1-x),height-2*padding,padding));
	}
	else if(x==1){
		subDivisions.push_back(
			new UIBox(posX+padding,posY+padding,width-2*padding,(height-2*padding)*y,padding));
		subDivisions.push_back(
			new UIBox(posX+padding,newY,width-2*padding,(height-2*padding)*1-y,padding));
	}else{
		subDivisions.push_back(
			new UIBox(posX+padding,posY+padding,(width-2*padding)*x,(height-2*padding)*y,padding));
		subDivisions.push_back(
			new UIBox(newX,posY+padding,(width-2*padding)*(1-x),(height-2*padding)*y,padding));
		subDivisions.push_back(
			new UIBox(posX+padding,newY,width-2*padding,(height-2*padding)*(1-y),padding));
	}
}

void UIBox::draw(SDL_Renderer* renderer){
	if(texture != NULL){
		SDL_Rect rect = {posX+padding,posY+padding,width-2*padding,height-2*padding};
		SDL_RenderCopy(renderer,texture,0,&rect);
	}
	for(int i=0;i<subDivisions.size();i++)
		subDivisions[i]->draw(renderer);
}

void UIBox::setTexture(SDL_Texture* txtr){
	texture = txtr;
}

vector<UIBox*> UIBox::getSubDivisions(){return subDivisions;}

bool UIBox::isPressed(SDL_Event* event,int mouseX,int mouseY){
	if(event->type == SDL_MOUSEBUTTONDOWN)
		if(mouseX > posX && mouseX < posX+width && mouseY > posY && mouseY < posY+height)
			return true;
	return false;
}

void UIBox::createGrid(int x,int y){
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			subDivisions.push_back(
				new UIBox(posX+padding+j*((width-2*padding)/x),posY+padding+i*(height/y),((width-2*padding)/x),height/y,padding));

}
