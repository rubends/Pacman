/*
 * Pacman.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Pacman.h"
#include "Factory.h"

Pacman::Pacman() {
	mPosX = 100;
	mPosY = 50;
	mVelX = 0;
	mVelY = 0;
	mWidth = 0;
	mHeight = 0;
	aFactory = NULL;
	collision = false;
}

Pacman::~Pacman() {
	// TODO Auto-generated destructor stub
}

void Pacman::setFactory(Factory* fac){
	aFactory = fac;
}

void Pacman::checkCollisions(Tile* tileSet[], int totalTiles){
	for(int j = 0; j <= totalTiles; j++){
		int *tileBoxInt = tileSet[j]->getBoxInt();
		int tileBox[4] = {  tileBoxInt[0], tileBoxInt[1], tileBoxInt[2], tileBoxInt[3] };

		int pacBox[4] = { mPosX, mPosY, mWidth, mHeight };
		if(tileBoxInt[4] != 0){
			bool tempCollide = aFactory->checkCollision(pacBox, tileBox);

			if(!collision && !tempCollide){
				collision = true;
				if(tileBoxInt[4] == 2){
					cout << "PELLET\n";
				}
			}
		}
	}
}

