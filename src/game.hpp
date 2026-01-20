#include "SDL2/SDL_mixer.h"
#include "SDL_video.h"
#include "SDL_render.h"
#pragma once

class game {
	public:
		game();
		~game();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		int initSound(const char *filename);

		void handleEvents();
		void update();
		void render();
		void clean();

		bool running() {   //why do I have a wrapper function returning a private data value? why not make the data public?
			return isRunning;
		}
		static SDL_Renderer *renderer;
		static int winWidth, winHeight;
	private:
		bool isRunning;
		float cnt;
		SDL_Window *window;
		Mix_Chunk *popChunk;
};
