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

	bool checkCollision(int* a, int* b);
	Tile** getMapTiles();
	int GetScreenWidth();
	int GetScreenHeight();
	int GetNumOfTiles();
	string GetMapName();
	int GetScore();
	int AddToScore(int addition);
	int GetLives();
	int SubtractLives(int subtraction);
	int GetTileSize();
	std::vector<Ghost*> GetGhosts();
	bool GetPlaying();
	bool SetPlaying(bool play, string text);
	void ResetGame();

	virtual Ghost* createGhost(int type) = 0;
	virtual Pacman* createPacman() = 0;
	virtual Tile* createTile(int x, int y, int type, int width, int height) = 0;
	virtual void DestroyTile(int tile) = 0;
	virtual Map* createMap() = 0;
	virtual void UpdateText() = 0;
	virtual void ClearScreen() = 0;
	virtual void UpdateScreen() = 0;
	virtual void quitVis() = 0;
protected:
	int screenWidth;
	int screenHeight;
	int numOftiles;
	std::ifstream mapStream;
	Map* tileMap;
	std::vector<Ghost*> ghosts;

	int tileSize = 20;
	int highScore = 0;
	int score = 0;
	int lives = 3;
	bool playing = false;
	string startText = "Start";
	string mapName = "Assets/Map2.map";
};

#endif /* FACTORY_H_ */
