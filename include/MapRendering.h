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
	MapRenderer(Camera*,Map*);
	void drawMap();
	Map* getMap();
	void setMap(Map*);
};


