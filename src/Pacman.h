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

class Pacman {
public:
	Pacman();
	virtual ~Pacman();
	void CheckCollisions(Tile** tileSet);
	virtual void Visualize() = 0;
	virtual void Animate() = 0;
	virtual void Move(int key) = 0;
	virtual void Load() = 0;
	static const int PACMAN_VEL = 10;
protected:
	 int mPosX, mPosY;
	 int mVelX, mVelY;
};

#endif /* PACMAN_H_ */
