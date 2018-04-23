/*
 * Factory.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Factory.h"

Factory::Factory() {
	tileMap = NULL;

	mapStream.open("Assets/Map2.map", std::ios::binary);
	if( mapStream.fail() )
	{
		printf( "Unable to load map file!\n" );
	}

	char line[256];
	mapStream.getline(line, 256); //get position at first line
	int lineLength = mapStream.tellg()/2;

	mapStream.seekg(0, ios::end); //to the end of the file
	numOftiles = mapStream.tellg()/2; //get the number of tiles

	screenWidth = lineLength * tileSize;
	screenHeight = (numOftiles/lineLength) * tileSize;
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

	if( rightA > leftB && leftA < rightB && topA < bottomB && bottomA > topB)
	{
		return true;
	}

	return false;
}

int Factory::GetScreenWidth(){
	return screenWidth;
}

int Factory::GetScreenHeight(){
	return screenHeight;
}

int Factory::GetNumOfTiles(){
	return numOftiles;
}

int Factory::GetScore(){
	return score;
}

int Factory::GetLives(){
	return lives;
}

int Factory::SubtractLives(int subtraction){
	lives = lives + subtraction;
	return lives;
}

std::ifstream Factory::GetMapStream(){
	return mapStream;
}

int Factory::AddToScore(int addition){
	score = score + addition;
	return score;
}

int Factory::GetTileSize(){
	return tileSize;
}

std::vector<Ghost*> Factory::GetGhosts(){
	return ghosts;
}

