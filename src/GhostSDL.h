/*
 * GhostSDL.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef GHOSTSDL_H_
#define GHOSTSDL_H_

#include "Ghost.h"
#include <iostream>

class GhostSDL : public Ghost{
public:
	GhostSDL();
	virtual ~GhostSDL();
	void visualize(string name);
};

#endif /* GHOSTSDL_H_ */
