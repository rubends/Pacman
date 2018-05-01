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
	int last_frame = 0;
	clock_t ticks = 0;
	int clock_ms = 0; //clock in ms
	int countingAttack = 0;
	bool quit = false;

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
				if(ev->getKeyDown() == 6){ //pressed enter
					aFactory->SetPlaying(!aFactory->GetPlaying(), "Paused");

					if(!pacman->GetLiving()){
						pacman->SetLiving(true);
						for(int j=0; j < numOfGhosts;j++){
							ghosts[j]->ResetGhost();
						}
						if(aFactory->GetLives() <= 0){
							aFactory->ResetGame();
							pacman->SetDirection(4);
						}
					}
				} else if (aFactory->GetPlaying()) { //not changing direction while paused
					pacman->SetDirection(ev->getKeyDown());
				}
			}
		}

		if(!ghosts[0]->GetAttackingState()){ //if ghosts vulnerable
			if(countingAttack == 0){
				countingAttack = countToAttacking;
			} else if(countingAttack == 1){
				for(int j=0; j < numOfGhosts;j++){ // set ghosts back to attacking
					ghosts[j]->SetAttackingState(true);
				}
			}
		}

		ticks = clock(); //#clock ticks since running
		clock_ms = (ticks/(double)CLOCKS_PER_SEC)*1000.0; //#ms since running

		if(last_frame != clock_ms && clock_ms % mspf == 0){
			last_frame = clock_ms; //make sure not multiple frames in same ms

			aFactory->ClearScreen();
			map->Draw();
			if(aFactory->GetPlaying())
			{
				pacman->Move();
				ghosts[0]->MoveTo(pacman->GetX(), pacman->GetY());
				ghosts[1]->MoveTo(pacman->GetX()+80, pacman->GetY()+80); // todo verbeteren
				pacman->GotCaptured(ghosts, numOfGhosts);
				for(int j=2; j < numOfGhosts;j++){
					ghosts[j]->Move();
				}
			} else {
				pacman->Visualize();
				for(int j=0; j < numOfGhosts;j++){
					ghosts[j]->Visualize();
				}
			}
			if(clock_ms % (animationSpeed*mspf) == 0){ //every x frames animation
				pacman->Animate();
			}

			if(countingAttack > 0){
				countingAttack--;
				if(countingAttack <= 30 && clock_ms % (animationSpeed*mspf) == 0){
					for(int j=0; j < numOfGhosts;j++){
						ghosts[j]->SetFlashingState(!ghosts[j]->GetFlashingState());
					}
				}
			}

			aFactory->UpdateText();
			aFactory->UpdateScreen();
		}
	}
}

