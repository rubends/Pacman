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
#include "FactorySDL.h"

using namespace std;

class FactorySDL; //forward declaration for construct
class PacmanSDL : public Pacman{
public:
	PacmanSDL(SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface);
	virtual ~PacmanSDL();
	void visualize();
	void move();
	void moveInDir(int direction);
	void SetDirection(int key);
protected:
	SDL_Renderer* sdlRenderer;
	SDL_Surface* surface;

	SDL_Rect pacmanSprite[3];
	SDL_Texture* pacTexture = NULL;
	SDL_Rect renderQuad;

	int frame = 0;
	int fps = 0;
	int direction = 4;
	int prevDirection = 4;
};

#endif /* PACMANSDL_H_ */
