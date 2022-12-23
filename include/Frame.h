#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Frame{
	int w, h;
	float dx,dy;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
public:
	Frame(SDL_Renderer*,string,float ,float );
	float getDx();
	float getDy();
	SDL_Texture* getTexture();
	SDL_Renderer* getRenderer();
	void Draw(int x,int y,int size);
};
