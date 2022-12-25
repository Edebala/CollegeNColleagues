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
	vector<SDL_Texture*> textures;
public:
	MapRenderer(SDL_Renderer*,Camera*,Map*);
	void drawMap();
};
void getBlockTexture(int block);
void drawMap();


