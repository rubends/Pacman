/*
 * Factory.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "Ghost.h"
#include "Pacman.h"
#include "Map.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Map;
class Pacman;
class Ghost;
class Factory {
public:
	Factory();
	virtual ~Factory();

	bool CheckCollision(int* a, int* b);
	Tile** GetMapTiles();
	int GetScreenWidth();
	int GetScreenHeight();
	int GetNumOfTiles();
	string GetMapName();
	int GetScore();
	int AddToScore(int addition);
	int GetLives();
	int SubtractLives(int subtraction);
	int GetTileSize();
	void DestroyTile(int tile);
	std::vector<Ghost*> GetGhosts();
	bool GetPlaying();
	bool SetPlaying(bool play, string text);
	void ResetGame();

	virtual Ghost* CreateGhost(int type) = 0;
	virtual Pacman* CreatePacman() = 0;
	virtual Tile* CreateTile(int x, int y, int type, int width, int height) = 0;
	virtual Map* CreateMap() = 0;
	virtual void UpdateText() = 0;
	virtual void ClearScreen() = 0;
	virtual void UpdateScreen() = 0;
	virtual void QuitVis() = 0;
protected:
	int screenWidth;
	int screenHeight;
	int numOftiles;
	std::ifstream mapStream;
	Map* tileMap;
	std::vector<Ghost*> ghosts;

	int highScore = 0;
	int score = 0;
	int lives = 3;
	bool playing = false;
	string startText = "Start";

	const string MAP_NAME = "Assets/Map2.map";
	const int TILE_SIZE = 20;
};

#endif /* FACTORY_H_ */
