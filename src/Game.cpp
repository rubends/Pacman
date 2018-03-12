/*
 * Game.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Game.h"
#include "Ghost.h"
#include "EventHandlerSDL.h"
#include "EventHandler.h"

Game::Game(Factory*& abstractFactory) {
	aFactory = abstractFactory;

}

Game::~Game(){

}

void Game::start(){
	Ghost* blinky = aFactory->createGhost("Blinky");
	Pacman* pac = aFactory->createPacman();

	EventHandler* ev = new EventHandlerSDL();

	bool quit = false;
	while( !quit )
	{
		while( ev->pollEvent() != 0 )
		{
			//User requests quit
			if( ev->quitEvent() )
			{
				quit = true;
				delete blinky;
				delete pac;
			} else if(ev->keyDown()){
				int key = ev->getKeyDown();
				cout << "\nkey: " << key; // log keystrokes
			}
		}
	}
}

