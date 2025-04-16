#pragma once
#include "SDL_render.h"
#include "SDL_rect.h"
#include "SDL_mixer.h"

class gameObject {
	public: 
		gameObject(const char *textureSheet, Mix_Chunk *, int initialX, int initialY);
		~gameObject();

		void update();	//now each object can have its own update function for its own behaviors
		void render();

	private:
		float xpos, ypos;
		bool xsub, ysub;
		float xDiff, yDiff;
		float xScale, yScale;

		SDL_Texture *objTexture;
		SDL_Rect srcRect, destRect;
		Mix_Chunk *chunk;
};
