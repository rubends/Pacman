/*
 * FactorySDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "FactorySDL.h"

FactorySDL::FactorySDL(){
	sdlInit = NULL;
	gContext = NULL;
}

FactorySDL::~FactorySDL(){

}

Ghost* FactorySDL::CreateGhost(int type){
	Ghost* ghost = new GhostSDL(type, sdlInit->GetRenderer(), sdlInit->GetSurface());
	ghost->SetFactory(this);
	ghosts.push_back(ghost);
	return ghost;
}

Pacman* FactorySDL::CreatePacman(){
	Pacman* pacman = new PacmanSDL(sdlInit->GetRenderer(), sdlInit->GetSurface());
	pacman->SetFactory(this);
	pacman->SetGameContext(gContext);

	return pacman;
}

Tile* FactorySDL::CreateTile(int x, int y, int type, int width, int height){
	Tile* tile = new TileSDL(sdlInit->GetRenderer(), sdlInit->GetTileTexture());
	tile->RenderTile(x, y, type, width, height);
	return tile;
}

void FactorySDL::CreateVis() {
	sdlInit = new InitSDL(tileMap->GetScreenWidth(), tileMap->GetScreenHeight());
}

GameContext* FactorySDL::CreateGameContext(){
	gContext = new GameContextSDL(sdlInit);
	tileMap->SetContext(gContext);
	return gContext;
}
