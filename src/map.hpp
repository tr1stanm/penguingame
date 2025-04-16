#pragma once
#include "SDL_rect.h"
#include "SDL_render.h"

class map {
	public:
		map();
		~map();

		void loadMap(int maparray[16][16]);
		void drawMap();
	private:
		SDL_Rect src, dest;
		SDL_Texture *ice;
		SDL_Texture *water;

		int tilemap[16][16];
};
