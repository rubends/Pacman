/*
 * Factory.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Factory.h"

Factory::Factory() {
	tileMap = NULL;

	cFile = new Config();
	mapName = cFile->getMapName();
	tileSize = cFile->getTileSize();
	lives = cFile->getLives();

	mapStream.open(mapName, std::ios::binary); // GET MAP RESOLUTION BEFORE LOADING SDL
	if( mapStream.fail() )
	{
		printf( "Unable to load map file!\n" );
	}

	char line[256];
	mapStream.getline(line, 256); //get position at first line
	int lineLength = mapStream.tellg()/2;

	mapStream.seekg(0, ios::end); //to the end of the file
	numOftiles = mapStream.tellg()/2; //get the number of tiles
	mapStream.close();

	screenWidth = lineLength * tileSize;
	screenHeight = (numOftiles/lineLength) * tileSize;
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
	lives = lives - subtraction;
	return lives;
}

string Factory::GetMapName(){
	return mapName;
}

int Factory::AddToScore(int addition){
	score = score + addition;
	return score;
}

int Factory::GetTileSize(){
	return tileSize;
}

void Factory::DestroyTile(int tile){
	tileMap->DestroyTile(tile);
}

std::vector<Ghost*> Factory::GetGhosts(){
	return ghosts;
}

bool Factory::GetPlaying(){
	return playing;
}

bool Factory::SetPlaying(bool play, string text){
	if(lives <= 0){
		playing = false;
		startText = "Game Over";
		if(score > highScore){
			highScore = score;
		}
	} else {
		playing = play;
		startText = text;
	}
	return playing;
}

void Factory::ResetGame(){
	score = 0;
	lives = 3; //todo get this
	startText = "Start again";
	tileMap->Load();
}

Config* Factory::GetConfig() {
	return cFile;
}
