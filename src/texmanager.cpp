#include "texmanager.hpp"
#include "SDL_image.h"
#include "game.hpp"

SDL_Texture *textureManager::loadTexture(const char *texture) {
	SDL_Surface *tempSurface = IMG_Load(texture);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex;
}

void textureManager::draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(game::renderer, texture, &src, &dest);
}

