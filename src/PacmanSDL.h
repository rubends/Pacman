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

class PacmanSDL : public Pacman{
public:
	PacmanSDL();
	virtual ~PacmanSDL();
	void visualize();
	void load();
	void animate();
	void move(int key);
private:
	SDL_Surface* loadedSurface;
};

#endif /* PACMANSDL_H_ */
