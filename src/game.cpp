#include "game.hpp"
#include "texmanager.hpp"
#include "gameObject.hpp"
#include "SDL.h"
#include "map.hpp"
#include <iostream>

const int PLAYERNUM = 5;
gameObject *players[PLAYERNUM];
gameObject *enemies[PLAYERNUM];
map *gameMap;
SDL_Renderer *game::renderer = nullptr;
int game::winWidth = 0;
int game::winHeight = 0;	//you gotta initialize the public static vars otherwise the compiler gets mad

game::game() {
	cnt = 0;
	window = nullptr;
}

game::~game()
{}

void game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	winWidth = width;
	winHeight = height;
	int flags = 0;
	if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;	//this is silly bc this SDL constant just == 1
	if(!SDL_Init(SDL_INIT_EVERYTHING)) {
		std::cout << "subsystems initialized..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(window) std::cout << "window created!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer) {
			//SDL_SetRenderDrawColor(renderer, 0, 50, 50, 255);
			//this isn't necessary when using tilemaps
			std::cout << "renderer created!" << std::endl;
		}
		isRunning = true;
	}
	else isRunning = false;

	for(int i = 0; i < PLAYERNUM; ++i) players[i] = new gameObject("assets/guin.png", popChunk, 0, 0);
	for(int i = 0; i < PLAYERNUM; ++i) enemies[i] = new gameObject("assets/guin.png", popChunk, 0, 0);
	gameMap = new map();
}

int game::initSound(const char *filename) {
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	popChunk = Mix_LoadWAV(filename);
	if(!popChunk) return -1;
	return 0;
}

void game::handleEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default: 
			break;
	}
}

void game::render(){
	SDL_RenderClear(renderer);
	
	//add things to render here
	//remember they render in the order listed!
	gameMap -> drawMap();
	for(int i = 0; i < PLAYERNUM; ++i) players[i] -> render();
	for(int i = 0; i < PLAYERNUM; ++i) enemies[i] -> render();

	SDL_RenderPresent(renderer);
}

void game::update() {
	
	for(int i = 0; i < PLAYERNUM; ++i) players[i] -> update();
	for(int i = 0; i < PLAYERNUM; ++i) enemies[i] -> update();

	/*
	cnt += 0.3;
	cnt *= 1.005;
	if(cnt >= 800) cnt = 0;


	destRect.h = 64-cnt/10;
	destRect.w = 64+cnt/2;
	//destRect.x = 100*cos(cnt/5) + 200;
	destRect.x = 100*cos(cnt) + 200;
	destRect.y = (100+cnt/2)*sin(cnt/5) + 200;

	std::cout << cnt << '\r' << std::flush;
	*/
}

void game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned." << std::endl;
}



