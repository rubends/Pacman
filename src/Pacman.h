/*
 * Pacman.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef PACMAN_H_
#define PACMAN_H_

#include <iostream>
#include "Entity.h"
#include "Ghost.h"
using namespace std;

class Pacman : public Entity{
public:
	Pacman();
	virtual ~Pacman();
	int GetX();
	int GetY();
	void SetDirection(int key);

	virtual void Visualize() = 0;
	virtual void Animate() = 0;
	virtual void MoveInDir(int direction) = 0;
	virtual void Move() = 0;
	virtual void GotCaptured(Ghost* ghosts[], int numOfGhosts) = 0;
protected:
	int PACMAN_VEL = 5;
	bool living = true;
	int direction = 4;
	int prevDirection = 4;
};

#endif /* PACMAN_H_ */
