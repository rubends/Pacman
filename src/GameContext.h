/*
 * GameContext.h
 *
 *  Created on: May 15, 2018
 *      Author: ruben
 */

#ifndef GAMECONTEXT_H_
#define GAMECONTEXT_H_

#include "Ghost.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Ghost;
class GameContext {
public:
	GameContext();
	virtual ~GameContext();

	int GetLives();
	int SubtractLives(int subtraction);
	bool GetPlaying();
	bool SetPlaying(bool play, string text);
	int GetScore();
	int AddToScore(int addition);
	int SetScreenWidth(int sWidth);
	int SetScreenHeight(int sHeight);
	int GetScreenWidth();
	int GetScreenHeight();
	int SetTotalTiles(int totalTiles);
	int GetTotalTiles();
	int SetTileSize(int size);
	int GetTileSize();
	void ResetGame();

	virtual void UpdateText() = 0;
	virtual void PlaySound(string sound) = 0;
	virtual void ClearScreen() = 0;
	virtual void UpdateScreen() = 0;
	virtual void QuitVis() = 0;
protected:
	int screenWidth = 0;
	int screenHeight = 0;
	int numOfTiles = 0;
	std::ifstream mapStream;
	std::vector<Ghost*> ghosts;

	int highScore = 0;
	int score = 0;
	bool playing = false;
	string startText = "Start";

	string mapName = "test";
	int tileSize = 20;
	int lives = 3;

};

#endif /* GAMECONTEXT_H_ */
