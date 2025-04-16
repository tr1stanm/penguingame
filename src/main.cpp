#include "SDL_timer.h"
#include "game.hpp"
#include <iostream>

game *newgame = nullptr;

int main() {
	const int FPS = 60;
	const int frameDelay = 1000/FPS;
	Uint32 frameStart;
	int frameTime;

	newgame = new game;

	if(!newgame -> initSound("assets/notif.wav")) std::cout << "sound loaded successfully." << std::endl;
	else std::cout << "sound not loaded." << std::endl;
	newgame -> init("engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, false);

	while(newgame -> running()) {				//game loop
		frameStart = SDL_GetTicks();

		newgame -> handleEvents();
		newgame -> update();
		newgame -> render();

		frameTime = SDL_GetTicks() - frameStart;	//gives time in ms for game to run one game loop
		
		if(frameTime < frameDelay) SDL_Delay(frameDelay - frameTime);
	}

	newgame -> clean();
	delete newgame;
	return 0;

}
