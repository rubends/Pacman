/*
 * GameContext.cpp
 *
 *  Created on: May 15, 2018
 *      Author: ruben
 */

#include "GameContext.h"

GameContext::GameContext() {
	// TODO Auto-generated constructor stub

}

GameContext::~GameContext() {
	// TODO Auto-generated destructor stub
}

int GameContext::GetLives(){
	return lives;
}


int GameContext::SubtractLives(int subtraction){
	lives = lives - subtraction;
	return lives;
}

bool GameContext::GetPlaying(){
	return playing;
}

bool GameContext::SetPlaying(bool play, string text){
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

int GameContext::GetScore(){
	return score;
}

int GameContext::AddToScore(int addition){
	score = score + addition;
	return score;
}

int GameContext::SetScreenWidth(int sWidth){
	screenWidth = sWidth;
	cout << screenWidth;
	return screenWidth;
}
int GameContext::SetScreenHeight(int sHeight){
	screenHeight = sHeight;
	return screenHeight;
}
int GameContext::GetScreenWidth(){
	cout << '-';
	cout << screenWidth; // CRASH
	return 560;
	return screenWidth;
}
int GameContext::GetScreenHeight(){
	return screenHeight;
}

int GameContext::SetTotalTiles(int totalTiles){
	numOfTiles = totalTiles;
	return numOfTiles;
}
int GameContext::GetTotalTiles(){
	return numOfTiles;
}

int GameContext::SetTileSize(int size){
	tileSize = size;
	return tileSize;
}

int GameContext::GetTileSize(){
	return tileSize;
}

void GameContext::ResetGame(){
	score = 0;
	lives = 3; //todo get this
	startText = "Start again";
}
