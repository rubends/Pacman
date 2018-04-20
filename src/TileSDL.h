/*
 * WallSDL.h
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#ifndef TILESDL_H_
#define TILESDL_H_

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include "Tile.h"

using namespace std;

class TileSDL : public Tile{
public:
	TileSDL(SDL_Renderer* sdlRendererTEMP, SDL_Texture* tileTexture);
	virtual ~TileSDL();
	void visualize();
	void renderTile(int x, int y, int tileType, int width, int height);
	int* getBoxInt();
protected:
	SDL_Renderer* sdlRenderer;
	SDL_Texture* texture;

	int boxInt [5];

	const int PATH = 0;
	const int WALL_VERT = 1;
	const int WALL_HORI = 2;
	const int WALL_COR_UP_LR = 3;
	const int WALL_COR_UP_RL = 4;
	const int WALL_COR_DOWN_RL = 5;
	const int WALL_COR_DOWN_LR = 6;

	const int PELLET = 9;
};

#endif /* TILESDL_H_ */
