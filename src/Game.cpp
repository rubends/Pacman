/*
 * Game.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Game.h"

Game::Game(Factory*& abstractFactory) {
	aFactory = abstractFactory;
}

Game::~Game(){

}

void Game::start(){
	Map* map = aFactory->createMap();
	Ghost* ghosts[numOfGhosts];
	for(int i = 0; i < numOfGhosts; i++){
		ghosts[i] = aFactory->createGhost(i);
	}

	Pacman* pacman = aFactory->createPacman();

	int fps = 0;

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
				//delete [] ghosts;
				delete pacman;
				delete ev;
				aFactory->quitVis();
			} else if(ev->keyDown()){
				pacman->SetDirection(ev->getKeyDown());
			}
		}

		if(fps >= 60){ //TODO global fps
			pacman->move();

			ghosts[0]->moveTo(pacman->getX(), pacman->getY());
			for(int j=1; j < numOfGhosts;j++){
				ghosts[j]->move();
			}
			fps = 0;
		}
		fps++;

		aFactory->ClearScreen();
		map->Draw();
		pacman->visualize();
		for(int k=0; k < numOfGhosts;k++){
			ghosts[k]->visualize();
		}

		aFactory->UpdateScreen();
	}
}

