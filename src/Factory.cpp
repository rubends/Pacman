/*
 * Factory.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Factory.h"

Factory::Factory() {
	tileMap = NULL;
	cFile = NULL;
}

Factory::~Factory() {
	// TODO Auto-generated destructor stub
}

Tile** Factory::GetMapTiles() {
	return tileMap->GetTiles();
}

bool Factory::CheckCollision(int* entityBox, int* tileBox){
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = entityBox[0];
	rightA = entityBox[0] + entityBox[2]; // + width
	topA = entityBox[1];
	bottomA = entityBox[1] + entityBox[3]; // + height

	leftB = tileBox[0];
	rightB = tileBox[0] + tileBox[2]; // + width
	topB = tileBox[1];
	bottomB = tileBox[1] + tileBox[3]; // + height

	if( rightA > leftB && leftA < rightB && topA < bottomB && bottomA > topB)
	{
		return true;
	}

	return false;
}

void Factory::DestroyTile(int tile){
	tileMap->DestroyTile(tile);
}

std::vector<Ghost*> Factory::GetGhosts(){
	return ghosts;
}

Config* Factory::CreateConfig() {
	cFile = new Config();
	return cFile;
}

Map* Factory::CreateMap() {
	tileMap = new Map(this, cFile->GetMapName(), cFile->GetTileSize());
	this->CreateVis();
	tileMap->CreateMap();
	return tileMap;
}
