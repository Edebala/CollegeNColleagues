#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
class Map;
class Entity;
class Camera;

class MapRenderer{
	SDL_Renderer* renderer;
	SDL_Window* window;
	Map *map;
	vector<Entity*> entities;
public:
	MapRenderer(SDL_Renderer*,SDL_Window*,Map*);
	drawMap();
};
void getBlockTexture(int block);
void drawMap(Map*,Camera*);


