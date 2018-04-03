/*
 * Map.h
 *
 *  Created on: Mar 14, 2018
 *      Author: ruben
 */

#ifndef MAP_H_
#define MAP_H_

#include "Factory.h"
#include <fstream>
#include "Tile.h"

using namespace std;

class Factory; //TO USE
class Map {
public:
	const int TILE_WIDTH = 40;
	const int TILE_HEIGHT = 40;
	Map(Factory* aFactory);
	void Draw();
	Tile** GetTiles();
	virtual ~Map();
protected:
	const int totalTiles = 192;
	int SCREEN_WIDTH = 640;
	Tile* tileSet[192];

	Factory* aFactory = NULL;
	std::ifstream map;
};

#endif /* MAP_H_ */
