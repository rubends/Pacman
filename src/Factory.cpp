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

	leftA = entityBox[0];
	rightA = entityBox[0] + entityBox[2]; // + width
	topA = entityBox[1];
	bottomA = entityBox[1] + entityBox[3]; // + height

	leftB = tileBox[0];
	rightB = tileBox[0] + tileBox[2]; // + width
	topB = tileBox[1];
	bottomB = tileBox[1] + tileBox[3]; // + height

	/*if( bottomA > topB  && topA < bottomB && leftA < rightB && leftA > (leftB-width))
	{
		return true;
	}*/

	if( rightA > leftB && leftA < rightB && topA < bottomB && bottomA > topB)
	{
		return true;
	}

	return false;
}

int Factory::GetScreenWidth(){
	return SCREEN_WIDTH;
}

int Factory::GetNumOfTiles(){
	return numOftiles;
}

void Factory::SetNumOfTiles(int tiles){
	numOftiles = tiles;
}

int Factory::GetScore(){
	return score;
}

void Factory::AddToScore(int addition){
	score = score + addition;
}

std::vector<Ghost*> Factory::GetGhosts(){
	return ghosts;
}

