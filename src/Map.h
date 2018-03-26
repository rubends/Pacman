/*
 * Map.h
 *
 *  Created on: Mar 14, 2018
 *      Author: ruben
 */

#ifndef MAP_H_
#define MAP_H_

#include "Factory.h"

class Map {
public:
	const int TILE_WIDTH = 40;
	const int TILE_HEIGHT = 40;
	Map(Factory*& aFactory);
	void Draw();
	Tile** GetTiles();
	virtual ~Map();
};

#endif /* MAP_H_ */
