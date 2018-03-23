/*
 * PacmanSDL.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef PACMANSDL_H_
#define PACMANSDL_H_

#include "Pacman.h"
#include <iostream>

class PacmanSDL : public Pacman{
public:
	PacmanSDL();
	virtual ~PacmanSDL();
	void Visualize();
	void Animate();
	void Move(int key);
};

#endif /* PACMANSDL_H_ */
