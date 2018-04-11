/*
 * Map.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: ruben
 */

#include "Map.h"

int destroyedTiles[192] = { };

Map::Map(Factory* abstractFactory) {
	aFactory = abstractFactory;
	map.open("Assets/Map.map");
	if( map.fail() )
	{
		printf( "Unable to load map file!\n" );
	}
	map.seekg(0, ios::end);
	//totalTiles = map.tellg()/3; //size: no extra 0 or spaces = /3
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::Draw() {
	map.seekg(0, ios::beg); // go back to beginning of map

	int x = 0, y = 0;
	for(int tile = 0; tile < totalTiles; tile++){
		int tileType = 0;
		map >> tileType;
		if(destroyedTiles[tile] != 1){
			tileSet[tile] = aFactory->createTile(x, y, tileType, TILE_WIDTH, TILE_HEIGHT);
		}
		x += TILE_WIDTH;
		if(x >= SCREEN_WIDTH)
		{
			x = 0;
			y += TILE_HEIGHT;
		}
	}
}

Tile** Map::GetTiles(){
	return tileSet;
}

void Map::DestroyTile(int tile){
	destroyedTiles[tile] = 1;
}
