/*
 * WallSDL.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#include "TileSDL.h"

extern SDL_Renderer* sdlRendererTEMP; //TODO get from factory

TileSDL::TileSDL() {
}

TileSDL::~TileSDL() {
	// TODO Auto-generated destructor stub
}

void TileSDL::renderTile(int x, int y, int tileType, int width, int height) {
	boxInt[0] = x;
	boxInt[1] = y;
	boxInt[2] = width;
	boxInt[3] = height;
	boxInt[4] = tileType;

	if(tileType == WALL){
		SDL_Rect fillRect2 = { x, y, width, height };
		SDL_SetRenderDrawColor( sdlRendererTEMP, 0x00, 0x00, 0xFF, 0xFF );
		SDL_RenderFillRect( sdlRendererTEMP, &fillRect2 );
	} else if (tileType == PELLET){
		SDL_Rect fillRect2 = { x, y, width, height };
		SDL_SetRenderDrawColor( sdlRendererTEMP, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderFillRect( sdlRendererTEMP, &fillRect2 );
	} else {
		SDL_Rect fillRect2 = { x+(width/2)-(width/8), y+(height/2)-(height/8), width/4, height/4 };
		SDL_SetRenderDrawColor( sdlRendererTEMP, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderFillRect( sdlRendererTEMP, &fillRect2 );
	}
}

void TileSDL::visualize()
{
}

int* TileSDL::getBoxInt()
{
	return boxInt;
}

void TileSDL::destroyTile(){
	cout << "PELLET\n";
}

