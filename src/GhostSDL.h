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

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

using namespace std;

class GhostSDL : public Ghost{
public:
	GhostSDL(int ghostType);
	virtual ~GhostSDL();
	void visualize();
	void move();
	void moveTo(int x, int y);
protected:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Rect ghostSprite[3];
	SDL_Texture* ghostTexture = NULL;
	SDL_Rect renderQuadG;
};

#endif /* GHOSTSDL_H_ */
