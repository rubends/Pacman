/*
 * FactorySDL.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef FACTORYSDL_H_
#define FACTORYSDL_H_

#include "Factory.h"
#include "Ghost.h"
#include "GhostSDL.h"
#include "Pacman.h"
#include "PacmanSDL.h"

class FactorySDL : public Factory{
	public:
		FactorySDL();
		Ghost* createGhost(string name);
		Pacman* createPacman();
	};

#endif /* FACTORYSDL_H_ */
