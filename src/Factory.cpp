/*
 * Factory.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Factory.h"

Factory::Factory() {
}

Factory::~Factory() {
	// TODO Auto-generated destructor stub
}

bool Factory::checkCollision(int* pacBox, int* tileBox){
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	int width = tileBox[2];
	int height = tileBox[3];

	leftA = pacBox[0];
	rightA = pacBox[0] + width;
	topA = pacBox[1];
	bottomA = pacBox[1] + height;

	leftB = tileBox[0];
	rightB = tileBox[0] + width;
	topB = tileBox[1];
	bottomB = tileBox[1] + height;

	if( bottomA >= topB  && topA <= bottomB && leftA < rightB && leftA > (leftB-width))
	{
		cout << "Collision Y \n";
		return false;
	}

	if( rightA >= leftB && leftA <= rightB && topA < bottomB && bottomA > (topB+height))
	{
		cout << "Collision X \n";
		return false;
	}

	return true;
}

