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
	TileSDL();
	virtual ~TileSDL();
	void visualize();
	void renderTile(int x, int y, int tileType, int width, int height);
	int* getBoxInt();
protected:
	int boxInt [5];

	const int PATH = 00;
	const int WALL_VERT = 01;
	const int WALL_HORI = 02;
	const int WALL_COR_UP_LR = 03;
	const int WALL_COR_UP_RL = 04;
	const int WALL_COR_DOWN_RL = 05;
	const int WALL_COR_DOWN_LR = 06;
	const int PELLET = 10;
};

#endif /* TILESDL_H_ */
