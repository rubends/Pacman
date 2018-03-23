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

class TileSDL : public Tile{
public:
	TileSDL();
	virtual ~TileSDL();
	void visualize();
	void renderTile(int x, int y, int tileType, int width, int height);
	SDL_Rect getBox();
private:
	//attributes
	SDL_Rect mBox;
};

#endif /* TILESDL_H_ */
