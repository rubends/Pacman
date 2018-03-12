//============================================================================
// Name        : PacMan
// Author      : Ruben DS
// Version     :
// Copyright   : 
// Description : PacMan
//============================================================================

#include <iostream>

#include "Factory.h"
#include "FactorySDL.h"
#include "Game.h"

using namespace std;

int main(int argc, char* args[]) { //parameters for SDL
	Factory* aFactory = new FactorySDL();
	Game* game = new Game(aFactory);
	game->start();
	delete aFactory;
	delete game;

	return 0;
}
