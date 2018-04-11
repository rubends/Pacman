/*
 * Entity.h
 *
 *  Created on: Apr 2, 2018
 *      Author: ruben
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
#include "Tile.h"
using namespace std;

class Factory; //Forward declaration so the compiler knows what Factory is --> to use checkCollision
class Entity {
public:
	Entity();
	virtual ~Entity();
	void setFactory(Factory* fac);
	bool checkCollisions();
protected:
	Factory* aFactory;
	bool collision;
	int mPosX, mPosY;
	int mWidth, mHeight;
	int isPac;
};

#endif /* ENTITY_H_ */
