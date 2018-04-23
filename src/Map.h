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
	Map(Factory* aFactory);
	void Draw();
	Tile** GetTiles();
	void DestroyTile(int tile);
	virtual ~Map();
protected:
	int totalTiles;
	//TODO tile array variable size
	Tile** tileSet = new Tile*[868]; //** --> Cannot instantiate abstract object
	int* destroyedTiles = new int [868];
	Factory* aFactory;
	std::ifstream map;
};

#endif /* MAP_H_ */
