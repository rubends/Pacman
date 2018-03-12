/*
 * Factory.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "Ghost.h"
#include "Pacman.h"
#include <iostream>
using namespace std;

class Factory {
public:
	Factory();
	virtual ~Factory();
	virtual Ghost* createGhost(string name) = 0;
	virtual Pacman* createPacman() = 0;
};

#endif /* FACTORY_H_ */
