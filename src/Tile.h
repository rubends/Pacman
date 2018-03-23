/*
 * Wall.h
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#ifndef TILE_H_
#define TILE_H_
#include <iostream>
using namespace std;

class Tile {
public:
	Tile();
	virtual ~Tile();
	virtual void visualize() = 0;
	virtual void renderTile(int x, int y, int tileType, int width, int height) = 0;
};

#endif /* TILE_H_ */
