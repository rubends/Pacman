/*
 * Game.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Game.h"
#include <fstream>

Game::Game(Factory*& abstractFactory) {
	aFactory = abstractFactory;
	//this->GetSettings(); todo
}

Game::~Game(){

}

void Game::GetSettings(){
	std::ifstream configFile("Assets/config.json", std::ifstream::binary);
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

			aFactory->ClearScreen();
			map->Draw();
			aFactory->UpdateText();
			pacman->Move();
			ghosts[0]->MoveTo(pacman->GetX(), pacman->GetY());
			ghosts[1]->MoveTo(pacman->GetX()+80, pacman->GetY()+80); // todo verbeteren
			pacman->GotCaptured(ghosts, numOfGhosts);
			for(int j=2; j < numOfGhosts;j++){
				ghosts[j]->Move();
			}

			if(clock_ms % (animationSpeed*mspf) == 0){ //every x frames animation
				pacman->Animate();
			}

			aFactory->UpdateScreen();
		}
	}
}

