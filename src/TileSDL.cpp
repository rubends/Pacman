/*
 * WallSDL.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#include "TileSDL.h"

extern SDL_Renderer* sdlRendererTEMP; //TODO get from factory
extern SDL_Texture* tileTexture;

SDL_Rect tileSprite[6];
SDL_Rect pickUps[1];

TileSDL::TileSDL() {
	tileSprite[0].x = 228;
	tileSprite[0].y = 12;
	tileSprite[0].w = 5;
	tileSprite[0].h = 15;

	tileSprite[1].x = 234;
	tileSprite[1].y = 0;
	tileSprite[1].w = 15;
	tileSprite[1].h = 5;

	tileSprite[2].x = 228;
	tileSprite[2].y = 0;
	tileSprite[2].w = 5;
	tileSprite[2].h = 15;

	tileSprite[3].x = 447;
	tileSprite[3].y = 0;
	tileSprite[3].w = 5;
	tileSprite[3].h = 15;

	tileSprite[4].x = 447;
	tileSprite[4].y = 75;
	tileSprite[4].w = 5;
	tileSprite[4].h = 15;

	tileSprite[5].x = 228;
	tileSprite[5].y = 75;
	tileSprite[5].w = 5;
	tileSprite[5].h = 15;

	pickUps[0].x = 8;
	pickUps[0].y = 24;
	pickUps[0].w = 8;
	pickUps[0].h = 8;
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

	if(tileType == WALL_VERT){
		SDL_Rect tileRect = { x, y, width, height };
		SDL_RenderCopy( sdlRendererTEMP, tileTexture, &tileSprite[0], &tileRect );
	} else if(tileType == WALL_HORI){
		SDL_Rect tileRect = { x, y, width, height };
		SDL_RenderCopy( sdlRendererTEMP, tileTexture, &tileSprite[1], &tileRect );
	} else if(tileType == WALL_COR_UP_LR){
		SDL_Rect tileRect = { x, y, width, height };
		SDL_RenderCopy( sdlRendererTEMP, tileTexture, &tileSprite[2], &tileRect );
	} else if(tileType == WALL_COR_UP_RL){
		SDL_Rect tileRect = { x, y, width, height };
		SDL_RenderCopy( sdlRendererTEMP, tileTexture, &tileSprite[3], &tileRect );
	} else if(tileType == WALL_COR_DOWN_RL){
		SDL_Rect tileRect = { x, y, width, height };
		SDL_RenderCopy( sdlRendererTEMP, tileTexture, &tileSprite[4], &tileRect );
	} else if(tileType == WALL_COR_DOWN_LR){
		SDL_Rect tileRect = { x, y, width, height };
		SDL_RenderCopy( sdlRendererTEMP, tileTexture, &tileSprite[5], &tileRect );
	} else if (tileType == PELLET){
		int size = width * 0.75;
		SDL_Rect dotRect = { x+((width-size)/2), y+((width-size)/2), size, size };
		SDL_RenderCopy( sdlRendererTEMP, tileTexture, &pickUps[0], &dotRect );
	} else { // PAC DOT
		int size = width * 0.25;
		SDL_Rect dotRect = { x+((width-size)/2), y+((width-size)/2), size, size };
		SDL_RenderCopy( sdlRendererTEMP, tileTexture, &pickUps[0], &dotRect );
	}
}

void TileSDL::visualize()
{
}

int* TileSDL::getBoxInt()
{
	return boxInt;
}

