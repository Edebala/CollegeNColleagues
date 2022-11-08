#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <unistd.h>

int** createMap(int n,int m){
	int **map = new int*[m];
	for(int i=0;i<m;i++)
		map[i] = new int[n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			map[i][j] = (i ==0 || j == 0 || i == m-1 || j == n-1);
		}
	}
	return map;
}

void drawMap(int n,int m,int **map,SDL_Renderer *renderer,int x, int y){
	int blockSize = 48;
 	SDL_RenderClear(renderer);
	SDL_Surface *picBuffer;
	picBuffer = IMG_Load("Assets/Grass.png");
	SDL_Texture *GrassTxt = SDL_CreateTextureFromSurface(renderer,picBuffer);
	picBuffer = IMG_Load("Assets/Stone.png");
	SDL_Texture *StoneTxt = SDL_CreateTextureFromSurface(renderer,picBuffer);
	picBuffer = IMG_Load("Assets/Untitled.png");
	Uint32 colorkey = SDL_MapRGB(picBuffer->format, 255, 255, 255);
	SDL_SetColorKey(picBuffer, SDL_TRUE, colorkey);
	SDL_Texture *PlayerTxt = SDL_CreateTextureFromSurface(renderer,picBuffer);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			SDL_Texture *drawTxt = map[i][j]?StoneTxt:GrassTxt;
			SDL_Rect rect = {i*blockSize,j*blockSize,blockSize,blockSize};
			SDL_RenderCopy(renderer,drawTxt,0,&rect);
			if(i==x && j == y){
				drawTxt = PlayerTxt;
				SDL_RenderCopy(renderer,drawTxt,0,&rect);
			}
		}
	}
 	SDL_RenderPresent(renderer);
	sleep(1);
}

int main(int argc, const char * argv[]) {
	SDL_Window *window = SDL_CreateWindow(
	"CollegeNColleges",SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,800,800,
	SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(
	window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	int n=13,m=16,x=6,y=6;
	int **map = createMap(n,m);
	const unsigned char* key;
	while(x<m-1){
		SDL_PollEvent(&event);
		key = SDL_GetKeyboardState(0);
		if(key[SDL_SCANCODE_W]) y--;
		if(key[SDL_SCANCODE_S]) y++;
		if(key[SDL_SCANCODE_A]) x--;
		if(key[SDL_SCANCODE_D]) x++;
		drawMap(n,m,map,renderer,x,y);
	}
	return 0;
}
