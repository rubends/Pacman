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
		tileSet[tile] = aFactory->CreateTile(x, y, tileType, tileWidth, tileHeight);
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

void Map::Load() {
	cout << "RELOAD";
	for(int tile = 0; tile < totalTiles; tile++){
		destroyedTiles[tile] = 0;
	}
}

void Map::Draw() {
	for(int tile = 0; tile < totalTiles; tile++){
		if(destroyedTiles[tile] != 1){
			tileSet[tile]->Visualize();
		}
	}
}

Tile** Map::GetTiles(){
	return tileSet;
}

void Map::DestroyTile(int tile){
	if(destroyedTiles[tile] != 1){
		int* tileBoxInt = tileSet[tile]->GetBoxInt();
		if(tileBoxInt[4] == 9){ // PELLET TODO get variable int of pellet
			std::vector<Ghost*>ghosts = aFactory->GetGhosts();
			for(size_t i = 0; i <= (ghosts.size()-1); i++){
				ghosts[i]->SetAttackingState(false);
			}
			destroyedTiles[tile] = 1;
		} else if(tileBoxInt[4] == 8){ // CHERRY
			aFactory->AddToScore(10);
			destroyedTiles[tile] = 1;
		} else if(tileBoxInt[4] == 0){ //PAC-DOT
			aFactory->AddToScore(1);
			destroyedTiles[tile] = 1;
		}
		delete tileBoxInt;
	}
}
