/*
 * Map.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: ruben
 */

#include "Map.h"
#include "Tile.h"
#include "Factory.h"
#include <fstream>

const int TOTAL_TILES = 192;
int SCREEN_WIDTH = 640;
Tile* tileSet[TOTAL_TILES];

Factory* aFactory = NULL;
std::ifstream map;

//Tile constants
Map::Map(Factory*& abstractFactory) {
	aFactory = abstractFactory;
	map.open("Assets/Map.map");
	if( map.fail() )
	{
		printf( "Unable to load map file!\n" );
	}

}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::Draw() {
	int x = 0, y = 0;
	for(int tile = 0; tile < TOTAL_TILES; tile++){
		int tileType = 0;
		map >> tileType;
		tileSet[tile] = aFactory->createTile(x, y, tileType, TILE_WIDTH, TILE_HEIGHT);

		x += TILE_WIDTH;
		if(x >= SCREEN_WIDTH)
		{
			x = 0;
			y += TILE_HEIGHT;
		}
	}
	// go back to beginning of map
	map.seekg(0, ios::beg);
}

Tile** Map::GetTiles(){
	return tileSet;
}
