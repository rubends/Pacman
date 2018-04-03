/*
 * Ghost.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */
#include "Ghost.h"

Ghost::Ghost(){
	type = 0;
	GHOST_VEL = 5;
	mPosX = 0;
	mPosY = 0;
	mWidth = 0;
	mHeight = 0;
}

Ghost::~Ghost() {
	// TODO Auto-generated destructor stub
}

void Ghost::setName(string givenName){
	name = givenName;
	cout << "\nHello, i'm " << name;
}


