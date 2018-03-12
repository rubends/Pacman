/*
 * EventHandlerSDL.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef EVENTHANDLERSDL_H_
#define EVENTHANDLERSDL_H_

#include "EventHandler.h"

class EventHandlerSDL : public EventHandler{
public:
	EventHandlerSDL();
	virtual ~EventHandlerSDL();
	int pollEvent();
	bool quitEvent();
	bool keyDown();
	int getKeyDown();
};

#endif /* EVENTHANDLERSDL_H_ */
