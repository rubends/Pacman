/*
 * WallSDL.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#include "TileSDL.h"
#include <sdl2/SDL.h>

extern SDL_Renderer* sdlRenderer;

const int TOTAL_WALLS = 192;
const int PATH = 00;
const int WALL = 01;
TileSDL::TileSDL() {

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

	if(tileType == WALL){
		SDL_Rect fillRect2 = { x, y, width, height };
		SDL_SetRenderDrawColor( sdlRenderer, 0x00, 0x00, 0xFF, 0xFF );
		SDL_RenderFillRect( sdlRenderer, &fillRect2 );
	}

	SDL_RenderPresent( sdlRenderer );

}

void TileSDL::visualize()
{
	//wallMap.render( mBox.x - camera.x, mBox.y - camera.y, &gTileClips[ mType ] );
}

SDL_Rect TileSDL::getBox()
{
    return mBox;
}

