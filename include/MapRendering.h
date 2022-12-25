#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
class Map;
class TextureUnit;
class Camera;

class MapRenderer{
	SDL_Renderer* renderer;
  Camera* camera;
	Map *map;
	vector<TextureUnit*> units;
public:
	MapRenderer(SDL_Renderer*,SDL_Window*,Map*);
	void drawMap();
};
void getBlockTexture(int block);
void drawMap();


