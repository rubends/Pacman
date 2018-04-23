/*
 * Wall.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: ruben
 */

#include "Tile.h"

Tile::Tile() {
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

void Tile::SetTileType(int type){
	boxInt[4] = type;
}
