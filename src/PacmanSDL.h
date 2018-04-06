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
#include <sdl2/SDL_image.h>
#include "Factory.h"

using namespace std;

class PacmanSDL : public Pacman{
public:
	PacmanSDL();
	virtual ~PacmanSDL();
	void visualize();
	void move(int key);
protected:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Rect pacmanSprite[3];
	SDL_Texture* pacTexture = NULL;
	SDL_Rect renderQuad;

	int frame = 0;
	int fps = 0;
};

#endif /* PACMANSDL_H_ */
