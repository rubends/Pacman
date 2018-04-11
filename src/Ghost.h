/*
 * Ghost.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef GHOST_H_
#define GHOST_H_
#include <iostream>
#include "Entity.h"
using namespace std;

//class Entity;
class Ghost : public Entity{
public:
	Ghost();
	virtual ~Ghost();
	virtual void visualize() = 0;
	virtual void move() = 0;
	virtual void moveTo(int x, int y) = 0;
protected:
	int type;
	int GHOST_VEL = 5;
};

#endif /* GHOST_H_ */
