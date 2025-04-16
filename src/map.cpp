#include "map.hpp"
#include "texmanager.hpp"

//another global var ig
int defaultmap[16][16] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0},
	{0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
};	//different textures for the map can be equal to different values

map::map(){
	ice = textureManager::loadTexture("assets/ice.png");
	water = textureManager::loadTexture("assets/water.png");
	loadMap(defaultmap);

	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;
}

map::~map(){
}

void map::loadMap(int maparray[16][16]) {
	for(int r = 0; r < 16; ++r) {
		for(int c = 0; c < 16; ++c) {
			tilemap[r][c] = defaultmap[r][c];
		}
	}
}

void map::drawMap() {
	int type = 0;
	for(int r = 0; r < 16; ++r) {
		for(int c = 0; c < 16; ++c) {
			type = defaultmap[r][c];
			dest.x = c * dest.w;
			dest.y = r * dest.h;
			switch(type) {
			case 0:
				textureManager::draw(ice, src, dest);
				break;
			case 1:
				textureManager::draw(water, src, dest);
				break;
			default:
				break;
			}
		}
	}

}
