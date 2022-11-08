#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <unistd.h>

int** createMap(int x,int y){
	int **map = new int*[y];
	for(int i=0;i<y;i++)
		map[i] = new int[x];
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			map[i][j] = (i ==0 || j == 0 || i == y-1 || j == x-1);
		}
	}
	return map;
}

void drawMap(int x,int y,int **map,SDL_Renderer *renderer){
	int blockSize = 48;
 	SDL_RenderClear(renderer);
	SDL_Surface *picBuffer;
	picBuffer = IMG_Load("Assets/Grass.png");
	SDL_Texture *GrassTxt = SDL_CreateTextureFromSurface(renderer,picBuffer);
	picBuffer = IMG_Load("Assets/Stone.png");
	SDL_Texture *StoneTxt = SDL_CreateTextureFromSurface(renderer,picBuffer);
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			SDL_Texture *drawTxt = map[i][j]?StoneTxt:GrassTxt;
			SDL_Rect rect = {i*blockSize,j*blockSize,blockSize,blockSize};
			SDL_RenderCopy(renderer,drawTxt,0,&rect);
		}
	}
	sleep(1);
 	SDL_RenderPresent(renderer);
}

int main(int argc, const char * argv[]) {
	SDL_Window *Window = SDL_CreateWindow(
	"CollegeNColleges",SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,800,800,
	SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(
	Window, -1, SDL_RENDERER_ACCELERATED);
	int x=13,y=16;
	int **map = createMap(x,y);

	for(int i=0;i<6;i++)
		drawMap(x,y,map,renderer);
	std::cout << "Hello, World!\n";
	return 0;
}
