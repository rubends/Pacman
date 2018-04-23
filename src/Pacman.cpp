/*
 * Pacman.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Pacman.h"

Pacman::Pacman() {
	mPosX = mWidth; // todo get variable
	mPosY = mHeight;

	isPac = true;
}

Pacman::~Pacman() {
	// TODO Auto-generated destructor stub
}

int Pacman::GetX() {
	return mPosX;
}

int Pacman::GetY() {
	return mPosY;
}

void Pacman::SetDirection(int key){
	if(direction != key){
		direction = key;
	}
}
