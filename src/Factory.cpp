/*
 * Factory.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Factory.h"

Factory::Factory() {
	tileMap = NULL;
}

Factory::~Factory() {
	// TODO Auto-generated destructor stub
}

Tile** Factory::getMapTiles() {
	return tileMap->GetTiles();
}

bool Factory::checkCollision(int* entityBox, int* tileBox){
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	int width = tileBox[2];
	int height = tileBox[3];

	leftA = entityBox[0];
	rightA = entityBox[0] + width;
	topA = entityBox[1];
	bottomA = entityBox[1] + height;

	leftB = tileBox[0];
	rightB = tileBox[0] + width;
	topB = tileBox[1];
	bottomB = tileBox[1] + height;

	if( bottomA > topB  && topA < bottomB && leftA < rightB && leftA > (leftB-width))
	{
		return false;
	}

	if( rightA > leftB && leftA < rightB && topA < bottomB && bottomA > (topB+height))
	{
		return false;
	}

	return true;
}

int Factory::GetScreenWidth(){
	return SCREEN_WIDTH;
}

