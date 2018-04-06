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

	/*for(int i = 1; i < 5; i++){
		Ghost* ghost = aFactory->createGhost(i);
	}*/
	Ghost* ghost1 = aFactory->createGhost(1);
	Ghost* ghost2 = aFactory->createGhost(2);
	Ghost* ghost3 = aFactory->createGhost(3);
	Ghost* ghost4 = aFactory->createGhost(4);

	Pacman* pacman = aFactory->createPacman();

	int key = 0;
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
				//delete blinky;
				//delete pacman;
				aFactory->quitVis();
			} else if(ev->keyDown()){
				key = ev->getKeyDown();
			}
		}

		if(fps >= 60){ //TODO global fps
			pacman->move(key); //Todo gettiles out of loop

			ghost1->moveTo(pacman->getX(), pacman->getY());
			ghost2->move();
			ghost3->move();
			ghost4->move();

			fps = 0;
		}
		fps++;

		aFactory->ClearScreen();
		map->Draw();
		pacman->visualize();
		ghost1->visualize();
		ghost2->visualize();
		ghost3->visualize();
		ghost4->visualize();
		aFactory->UpdateScreen();
	}
}

