/*
 * Pacman.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef PACMAN_H_
#define PACMAN_H_

#include <iostream>
using namespace std;

class Pacman {
public:
	Pacman();
	virtual ~Pacman();
	virtual void Visualize() = 0;
	virtual void Animate() = 0;
	virtual void Move(int key) = 0;

	static const int PACMAN_VEL = 10;
protected:
	 int mPosX, mPosY;
	 int mVelX, mVelY;
};

#endif /* PACMAN_H_ */
