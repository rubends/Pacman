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
using namespace std;

//class Entity;
class Pacman : public Entity{
public:
	Pacman();
	virtual ~Pacman();
	int getX();
	int getY();
	virtual void visualize() = 0;
	virtual void move() = 0;
	virtual void Animate() = 0;
	virtual void moveInDir(int direction) = 0;
	virtual void SetDirection(int key) = 0;
protected:
	 int PACMAN_VEL = 5;
};

#endif /* PACMAN_H_ */
