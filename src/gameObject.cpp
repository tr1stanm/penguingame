#include <random>
#include "gameObject.hpp"
#include "texmanager.hpp"
#include "game.hpp"

gameObject::gameObject(const char *textureSheet, Mix_Chunk *popChunk, int initialX, int initialY) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0,game::winWidth-32);
	std::uniform_real_distribution<> diff(0,2);
	
	objTexture = textureManager::loadTexture(textureSheet);
	chunk = popChunk;
	xpos = distrib(gen);
	ypos = distrib(gen);
	xsub = false;
	ysub = false;
	xDiff = diff(gen);
	yDiff = diff(gen);

}

gameObject::~gameObject() {

}

void gameObject::update() {
	xScale = 1+(xpos/(game::winWidth-32));
	yScale = 1+(ypos/(game::winWidth-32));

	xScale = yScale = 1;

	if(!xsub && xpos >= game::winWidth-(32 * xScale)) {
		xsub = true;
		Mix_PlayChannel(-1, chunk, 0);
	}
	if(!ysub && ypos >= game::winWidth-(32 * yScale)) {
		ysub = true;
		Mix_PlayChannel(-1, chunk, 0);
	}
	if(xpos <= 0) {
		xsub = false;
		Mix_PlayChannel(-1, chunk, 0);
	}
	if(ypos <= 0) {
		ysub = false;
		Mix_PlayChannel(-1, chunk, 0);
	}	//think about switch case here

	if(!xsub) xpos += xDiff;
	else xpos -= xDiff;
	if(!ysub) ypos += yDiff;
	else ypos -= yDiff;

	srcRect.h = 32;
	srcRect.w = 32;		//rescale the texture in the destRect
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * xScale;
	destRect.h = srcRect.h * yScale;
}

void gameObject::render() {
	SDL_RenderCopy(game::renderer, objTexture, &srcRect, &destRect);
}

