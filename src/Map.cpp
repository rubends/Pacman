/*
 * Map.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: ruben
 */

#include "Map.h"

Map::Map(Factory* abstractFactory) {
	aFactory = abstractFactory;

	map.open(aFactory->GetMapName(), std::ios::binary);
	totalTiles = aFactory->GetNumOfTiles();
	int screenWidth = aFactory->GetScreenWidth();
	int tileWidth = aFactory->GetTileSize();
	int tileHeight = aFactory->GetTileSize();
	int x = 0, y = 0;

	for(int tile = 0; tile < totalTiles; tile++){
		int tileType = 0;
		map >> tileType;
		tileSet[tile] = aFactory->createTile(x, y, tileType, tileWidth, tileHeight);
		x += tileWidth;
		if(x >= screenWidth)
		{
			x = 0;
			y += tileHeight;
		}
	}
}

Map::~Map() {
	delete [] destroyedTiles;
	for(int tile = 0; tile < totalTiles; tile++){
		delete tileSet[tile];
	}
	delete [] tileSet;
}

void Map::Draw() {
	for(int tile = 0; tile < totalTiles; tile++){
		if(destroyedTiles[tile] != 1){
			tileSet[tile]->visualize();
		}
	}
}

Tile** Map::GetTiles(){
	return tileSet;
}

void Map::DestroyTile(int tile){
	destroyedTiles[tile] = 1;
	tileSet[tile]->SetTileType(-1); //collision happens only once
}
