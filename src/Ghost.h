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

class Ghost : public Entity{
public:
	Ghost();
	virtual ~Ghost();
	void setName(string givenName);
	virtual void visualize() = 0;
	virtual void move(Tile* tileSet[]) = 0;
	virtual void moveTo(int x, int y) = 0;
protected:
	int type;
	string name;

	int GHOST_VEL;
	int mPosX, mPosY;
	int mWidth, mHeight;
};

#endif /* GHOST_H_ */
