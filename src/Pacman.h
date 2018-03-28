/*
 * Pacman.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef PACMAN_H_
#define PACMAN_H_

#include <iostream>
#include "Tile.h"
using namespace std;

class Factory; //Forward declaration so the compiler knows what Factory is
class Pacman {
public:
	Pacman();
	virtual ~Pacman();
	void setFactory(Factory* fac);
	void checkCollisions(Tile* tileSet[], int totalTiles);
	virtual void visualize() = 0;
	virtual void animate() = 0;
	virtual void move(int key) = 0;
	virtual void load() = 0;
	static const int PACMAN_VEL = 10;
protected:
	 int mPosX, mPosY;
	 int mVelX, mVelY;
	 int mWidth, mHeight;
	 Factory* aFactory;
	 bool collision;
};

#endif /* PACMAN_H_ */
