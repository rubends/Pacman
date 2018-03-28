/*
 * Game.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Game.h"
#include "Ghost.h"
#include "Map.h"
#include "EventHandlerSDL.h"
#include "EventHandler.h"


Game::Game(Factory*& abstractFactory) {
	aFactory = abstractFactory;

}

Game::~Game(){

}

void Game::start(){
	Map* map = new Map(aFactory);
	//Ghost* blinky = aFactory->createGhost("Blinky");
	Pacman* pacman = aFactory->createPacman();
	pacman->load();

	int key = 0;

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
				//delete blinky;
				//delete pacman;
				aFactory->quitVis();
			} else if(ev->keyDown()){
				key = ev->getKeyDown();
				pacman->move(key);

				pacman->checkCollisions(map->GetTiles(), 192);
			}
		}
		aFactory->ClearScreen();
		map->Draw();
		pacman->visualize();
		pacman->animate();
		aFactory->UpdateScreen();
	}
}

