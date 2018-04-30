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
	bool GetAttackingState();
	void SetAttackingState(bool attack);
	bool GetLivingState();
	void SetLivingState(bool live);
	virtual void Visualize() = 0;
	virtual void Move() = 0;
	virtual void MoveTo(int x, int y) = 0;
protected:
	int type;
	int GHOST_VEL = 4;
	bool attacking = true;
	bool living = true;
};

#endif /* GHOST_H_ */
