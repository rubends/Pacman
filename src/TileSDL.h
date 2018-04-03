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
	void destroyTile();
	SDL_Rect getBox();
protected:
	//attributes
	SDL_Rect mBox;
	int TILETYPE;

	const int PATH = 00;
	const int WALL = 01;
	const int PELLET = 02;
};

#endif /* TILESDL_H_ */
