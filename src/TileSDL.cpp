/*
 * WallSDL.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#include "TileSDL.h"

TileSDL::TileSDL(SDL_Renderer* sdlRendererTEMP, SDL_Texture* tileTexture) {
	sdlRenderer = sdlRendererTEMP;
	texture = tileTexture;
}

TileSDL::~TileSDL() {
	// TODO Auto-generated destructor stub
}

void TileSDL::renderTile(int x, int y, int tileType, int width, int height) {
	if (tileType == PELLET){
		int defWidth = width;
		width = defWidth * 0.75; // only 3/4 size of square
		height = width; //still a little square border box
		x = x+((defWidth-width)/2); //center of square
		y = y+((defWidth-width)/2);

	} else if (tileType == PATH) { // PAC DOT
		int defWidth = width;
		width = defWidth * 0.25; // only 1/4 size of square
		height = width; //still a little square border box
		x = x+((defWidth-width)/2); //center of square
		y = y+((defWidth-height)/2);
	}

	boxInt[0] = x;
	boxInt[1] = y;
	boxInt[2] = width;
	boxInt[3] = height;
	boxInt[4] = tileType;

	this->visualize();
}

void TileSDL::visualize()
{
	if(boxInt[4] == WALL_VERT){
		tileSprite.x = 228;
		tileSprite.y = 12;
		tileSprite.w = 5;
		tileSprite.h = 5;
	} else if(boxInt[4] == WALL_HORI){
		tileSprite.x = 234;
		tileSprite.y = 0;
		tileSprite.w = 5;
		tileSprite.h = 5;
	} else if(boxInt[4] == WALL_COR_UP_LR){
		tileSprite.x = 228;
		tileSprite.y = 0;
		tileSprite.w = 5;
		tileSprite.h = 5;
	} else if(boxInt[4] == WALL_COR_UP_RL){
		tileSprite.x = 448;
		tileSprite.y = 0;
		tileSprite.w = 5;
		tileSprite.h = 5;
	} else if(boxInt[4] == WALL_COR_DOWN_RL){
		tileSprite.x = 448;
		tileSprite.y = 74;
		tileSprite.w = 5;
		tileSprite.h = 5;
	} else if(boxInt[4] == WALL_COR_DOWN_LR){
		tileSprite.x = 228;
		tileSprite.y = 74;
		tileSprite.w = 5;
		tileSprite.h = 5;
	} else if(boxInt[4] == CHERRY){
		tileSprite.x = 487;
		tileSprite.y = 48;
		tileSprite.w = 15;
		tileSprite.h = 15;
	} else if((boxInt[4] == PELLET)||(boxInt[4] == PATH)){ //PELLET OR DOT
		tileSprite.x = 8;
		tileSprite.y = 24;
		tileSprite.w = 8;
		tileSprite.h = 8;
	}

	tileRect = { boxInt[0], boxInt[1], boxInt[2], boxInt[3] };
	SDL_RenderCopy( sdlRenderer, texture, &tileSprite, &tileRect );
}

int* TileSDL::getBoxInt()
{
	return boxInt;
}

