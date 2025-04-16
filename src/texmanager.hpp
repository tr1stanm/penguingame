#include "SDL_render.h"

class textureManager {
	public:
		static SDL_Texture *loadTexture(const char *filename);
		// static means that I don't have to instantiate an object and am instead calling 
		// a function of the class itself
		static void draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest);
};
