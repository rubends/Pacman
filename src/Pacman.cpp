/*
 * Pacman.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Pacman.h"

Pacman::Pacman() {
	mPosX = 40;
	mPosY = 40;
}

Pacman::~Pacman() {
	// TODO Auto-generated destructor stub
}

int Pacman::getX() {
	return mPosX;
}

int Pacman::getY() {
	return mPosY;
}

