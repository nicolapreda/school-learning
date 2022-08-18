#pragma once

#include "Platform/Platform.hpp"

// libraries for "rand" function
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace sf;
using namespace std;

/*
	Crea un’applicazione dev C++ testuale o grafica che permetta di gestire
	- la creazione
	- la visualizzazione
	- l’esplorazione
	di un labirinto.
	Il labirinto è composto da una matrice N x M di stanze.
	Ogni stanza è rappresentata da 4 porte (Nord, Est, Sud e Ovest) e un valore
	intero relativo all’eventuale quantità di risorse contenute in essa.
	Il salvataggio deve avvenire su file.
*/

class MainGame
{
private:
	// variables
	// window
	RenderWindow* window;
	Event event;
	VideoMode videoMode;

	// main font
	Font font;

	// game variables

	// matrix map
	int map[5][5];

public:
	// constructors
	MainGame();
	virtual ~MainGame();
	// accessors
	bool running();

	// functions
	void update();
	void pollEvents();
	void render();
};
