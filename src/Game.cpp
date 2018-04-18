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
	Pacman* pacman = aFactory->createPacman();
	Ghost* ghosts[numOfGhosts];
	for(int i = 0; i < numOfGhosts; i++){
		ghosts[i] = aFactory->createGhost(i);
	}

	EventHandler* ev = new EventHandlerSDL();
	while( !quit )
	{
		while( ev->pollEvent() != 0 )
		{
			//User requests quit
			if( ev->quitEvent() )
			{
				quit = true;
				for(int i = 0; i < numOfGhosts; i++){
					//delete ghosts[i];
				}
				//delete [] ghosts;
				//delete pacman;
				//delete ev;
				aFactory->quitVis();
			} else if(ev->keyDown()){
				pacman->SetDirection(ev->getKeyDown());
			}
		}

		ticks = clock(); //#clock ticks since running
		clock_ms = (ticks/(double)CLOCKS_PER_SEC)*1000.0; //#ms since running

		if(last_frame != clock_ms && clock_ms % mspf == 0){
			last_frame = clock_ms; //make sure not multiple frames in same ms

			pacman->move(); // calculations before clearing screen
			ghosts[0]->moveTo(pacman->getX(), pacman->getY());

			aFactory->ClearScreen();

			map->Draw();
			pacman->visualize();
			ghosts[0]->visualize();
			for(int j=1; j < numOfGhosts;j++){
				ghosts[j]->move(); //here for less forloops
				ghosts[j]->visualize();
			}

			if(clock_ms % (animationSpeed*mspf) == 0){ //every x frames animation
				pacman->Animate();
			}

			aFactory->UpdateScreen();
		}
	}
}

