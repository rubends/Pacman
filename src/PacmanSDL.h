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
#include <sdl2/SDL.h>
#include "FactorySDL.h"

class FactorySDL;
class PacmanSDL : public Pacman{
public:
	FactorySDL* factory;
	PacmanSDL(FactorySDL* fac);
	virtual ~PacmanSDL();
	void Visualize();
	void Load();
	void Animate();
	void Move(int key);
private:
	SDL_Surface* loadedSurface;
};

#endif /* PACMANSDL_H_ */
