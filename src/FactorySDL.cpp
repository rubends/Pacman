/*
 * FactorySDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "FactorySDL.h"

FactorySDL::FactorySDL(){

	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		sdlWindow = SDL_CreateWindow( "PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
		if( sdlWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			sdlRendererTEMP = SDL_CreateRenderer( sdlWindow, -1, SDL_RENDERER_ACCELERATED );
			sdlRenderer = sdlRendererTEMP;
			int imgFlags = IMG_INIT_PNG;
			//Initialize SDL_image
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			} else {
				sdlScreenSurface = SDL_GetWindowSurface( sdlWindow );
			}

			//Initialize SDL_ttf
			if(TTF_Init() < 0){
				printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", IMG_GetError() );
			} else {
				font = TTF_OpenFont("Fonts/emulogic.ttf", 10);
				fontBig = TTF_OpenFont("Fonts/emulogic.ttf", 40);
				white = {255, 255, 255};
				messageTexture = NULL;
				textSurface = NULL;
			}

			//Initialize SDL_mixer
			if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) // standard frq = 44100, hardware channels = 2 (stereo), sample size = audio chunks
			{
				printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
			}
			pacSound = Mix_LoadWAV( "Assets/Sounds/pacman_beginning.wav" );

			this->ClearScreen();

			loadedSurface = IMG_Load("Assets/sprites.png");
			SDL_SetColorKey(loadedSurface, SDL_TRUE, 0x000000 );

			tileTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, loadedSurface );
		}
	}
}

FactorySDL::~FactorySDL(){

}

Ghost* FactorySDL::CreateGhost(int type){
	Ghost* ghost = new GhostSDL(type, sdlRendererTEMP, loadedSurface);
	ghost->SetFactory(this);
	ghosts.push_back(ghost);
	return ghost;
}

Pacman* FactorySDL::CreatePacman(){
	Pacman* pacman = new PacmanSDL(sdlRendererTEMP, loadedSurface);
	pacman->SetFactory(this);

	return pacman;
}

Tile* FactorySDL::CreateTile(int x, int y, int type, int width, int height){
	Tile* tile = new TileSDL(sdlRendererTEMP, tileTexture);
	tile->RenderTile(x, y, type, width, height);
	return tile;
}

Map* FactorySDL::CreateMap() {
	tileMap = new Map(this);
	return tileMap;
}

void FactorySDL::UpdateText(){
	printTxt = "Score: " + std::to_string(score);
	textSurface = TTF_RenderText_Solid( font, printTxt.c_str(), white);
	messageTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, textSurface );

	messageRect = {20, 0, textSurface->w, textSurface->h};
	SDL_RenderCopy(sdlRendererTEMP, messageTexture, NULL, &messageRect);
	SDL_DestroyTexture(messageTexture); // MEMORY LEAKS OTHERWISE
	SDL_FreeSurface(textSurface);

	printTxt = "Lives: " + std::to_string(lives);
	textSurface = TTF_RenderText_Solid( font, printTxt.c_str(), white);
	messageTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, textSurface );

	messageRect = {screenWidth - textSurface->w - 20, 0, textSurface->w, textSurface->h};
	SDL_RenderCopy(sdlRendererTEMP, messageTexture, NULL, &messageRect);
	SDL_DestroyTexture(messageTexture);
	SDL_FreeSurface(textSurface);

	if(!playing){
		textSurface = TTF_RenderText_Solid( fontBig, startText.c_str(), white);
		messageTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, textSurface );
		messageRect = {screenWidth/2 - (textSurface->w/2), screenHeight/2 - (textSurface->h/2) - 40, textSurface->w, textSurface->h};
		SDL_RenderCopy(sdlRendererTEMP, messageTexture, NULL, &messageRect);
		SDL_DestroyTexture(messageTexture);
		SDL_FreeSurface(textSurface);

		textSurface = TTF_RenderText_Solid( font, "Press 'enter' to play", white);
		messageTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, textSurface );
		messageRect = {screenWidth/2 - (textSurface->w/2), screenHeight/2 - (textSurface->h/2), textSurface->w, textSurface->h};
		SDL_RenderCopy(sdlRendererTEMP, messageTexture, NULL, &messageRect);
		SDL_DestroyTexture(messageTexture);
		SDL_FreeSurface(textSurface);

		if(lives <= 0){
			printTxt = "High score: " + std::to_string(highScore);
			textSurface = TTF_RenderText_Solid( font, printTxt.c_str(), white);
			messageTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, textSurface );
			messageRect = {screenWidth/2 - (textSurface->w/2), screenHeight/2 - (textSurface->h/2) + 20, textSurface->w, textSurface->h};
			SDL_RenderCopy(sdlRendererTEMP, messageTexture, NULL, &messageRect);
			SDL_DestroyTexture(messageTexture);
			SDL_FreeSurface(textSurface);
		}
	}
}

void FactorySDL::ClearScreen(){
	SDL_SetRenderDrawColor( sdlRendererTEMP, 0x00, 0x00, 0x00, 0x00 );
	SDL_RenderClear( sdlRendererTEMP );
}

void FactorySDL::UpdateScreen(){
	sdlRenderer = sdlRendererTEMP;
	SDL_RenderPresent( sdlRenderer );
}

SDL_Surface* FactorySDL::GetSurface(){
	return loadedSurface;
}

void FactorySDL::QuitVis(){
	SDL_DestroyRenderer( sdlRendererTEMP );
	SDL_DestroyRenderer( sdlRenderer );
	SDL_DestroyWindow( sdlWindow );
	sdlRendererTEMP = NULL;
	sdlRenderer = NULL;
	sdlWindow = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

void FactorySDL::PlaySound(string sound){
	if(sound == "pacman"){
		if(Mix_Playing(2) != 0){
			Mix_HaltChannel(2);
			Mix_FreeChunk( pacSound );
			pacSound = Mix_LoadWAV( "Assets/Sounds/pacman_chomp.wav" );
		}
		if( Mix_Playing(1) == 0 )
		{
			Mix_PlayChannel( 1, pacSound, 0 );
		}
	} else if(sound == "beginning"){
		if(Mix_Playing(1) != 0){
			Mix_HaltChannel(1);
			Mix_FreeChunk( pacSound );
			pacSound = Mix_LoadWAV( "Assets/Sounds/pacman_beginning.wav" );
		}
		if( Mix_Playing(2) == 0 )
		{
			Mix_PlayChannel( 2, pacSound, 0 );
		}
	} else if(sound == "dead"){
		pacSound = Mix_LoadWAV( "Assets/Sounds/pacman_death.wav" );
		Mix_PlayChannel( -1, pacSound, 0 );
	} else if(sound == "kill"){
		pacSound = Mix_LoadWAV( "Assets/Sounds/pacman_eatghost.wav" );
		Mix_PlayChannel( -1, pacSound, 0 );
	}

}
