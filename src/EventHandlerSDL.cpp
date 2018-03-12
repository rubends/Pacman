/*
 * EventHandlerSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "EventHandlerSDL.h"
#include <sdl2/SDL.h>


SDL_Event e;
EventHandlerSDL::EventHandlerSDL() {
	// TODO Auto-generated constructor stub

}

EventHandlerSDL::~EventHandlerSDL() {
	// TODO Auto-generated destructor stub
}

int EventHandlerSDL::pollEvent() {
	return SDL_PollEvent( &e );
}

bool EventHandlerSDL::quitEvent() {
	if( e.type == SDL_QUIT )
	{
		return true;
	}
	return false;
}

bool EventHandlerSDL::keyDown() {
	if (e.type == SDL_KEYDOWN){
		return true;
	}
	return false;
}

int EventHandlerSDL::getKeyDown() {
	int key;

	enum KeyPressSurfaces
	{
	    KEY_PRESS_SURFACE_DEFAULT,
	    KEY_PRESS_SURFACE_UP,
	    KEY_PRESS_SURFACE_DOWN,
	    KEY_PRESS_SURFACE_LEFT,
	    KEY_PRESS_SURFACE_RIGHT,
	    KEY_PRESS_SURFACE_TOTAL
	};

	switch( e.key.keysym.sym )
	{
		case SDLK_UP:
			key = KEY_PRESS_SURFACE_UP;
		 	break;

		case SDLK_DOWN:
			key = KEY_PRESS_SURFACE_DOWN;
			break;

		case SDLK_LEFT:
			key = KEY_PRESS_SURFACE_LEFT;
			break;

		case SDLK_RIGHT:
			key = KEY_PRESS_SURFACE_RIGHT;
			break;

		default:
			key = KEY_PRESS_SURFACE_DEFAULT;
			break;
	}

	return key;
}

