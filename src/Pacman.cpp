/*
 * Pacman.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Pacman.h"

Pacman::Pacman() {
	mPosX = 20; // todo get variable
	mPosY = 40;

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

bool Pacman::GetLiving(){
	return living;
}

bool Pacman::SetLiving(bool alive){
	living = alive;
	if(alive){
		mPosX = 20; //todo get variable
		mPosY = 40;
	}
	return living;
}
