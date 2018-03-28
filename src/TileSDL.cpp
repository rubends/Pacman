/*
 * WallSDL.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#include "TileSDL.h"
#include <sdl2/SDL.h>

extern SDL_Renderer* sdlRendererTEMP;

const int TOTAL_WALLS = 192;
const int PATH = 00;
const int WALL = 01;
const int PELLET = 02;
TileSDL::TileSDL() {
	TILETYPE = 0;
}

TileSDL::~TileSDL() {
	// TODO Auto-generated destructor stub
}

void TileSDL::renderTile(int x, int y, int tileType, int width, int height) {
	//Get the offsets
	mBox.x = x;
	mBox.y = y;
	//Set the collision box
	mBox.w = width;
	mBox.h = height;

	TILETYPE = tileType;

	if(tileType == WALL){
		SDL_Rect fillRect2 = { x, y, width, height };
		SDL_SetRenderDrawColor( sdlRendererTEMP, 0x00, 0x00, 0xFF, 0xFF );
		SDL_RenderFillRect( sdlRendererTEMP, &fillRect2 );
	} else if (tileType == PELLET){
		SDL_Rect fillRect2 = { x, y, width, height };
		SDL_SetRenderDrawColor( sdlRendererTEMP, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderFillRect( sdlRendererTEMP, &fillRect2 );
	}
}

void TileSDL::visualize()
{
	//wallMap.render( mBox.x - camera.x, mBox.y - camera.y, &gTileClips[ mType ] );
}

SDL_Rect TileSDL::getBox()
{
    return mBox;
}

int* TileSDL::getBoxInt()
{
	int* box = new int[5];
	box[0] = mBox.x;
	box[1] = mBox.y;
	box[2] = mBox.w;
	box[3] = mBox.h;
	box[4] = TILETYPE;
	return box;
}

