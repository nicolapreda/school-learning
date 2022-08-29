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
	RenderWindow* window;
	Event event;
	VideoMode videoMode;

	void initializeVariables();
	void initWindow();
	void initPlayer();
	// variables
	void initTextureGrid();
	void initPlaneTable();
	void initMap(int lenth);
	void placeDoors();
	void winMenu();
	int checkDoorCollision();
	bool checkWallCollision();
	void resultPage(int result);
	int updateRoom(int addRoom);
	int updateScore(int addScore);
	int checkDoor(int room);

	// window

	// main font
	Font font;
	Texture playerTexture, wall, floor, doorTexture;

	//current position x and y into the map
	int currentPositionY;
	int currentPositionX;

	Sprite player, grid[187], door[4];
	RectangleShape planeTable;

	Text scoreString, roomString, lifeString;
	int life, buttonResultSelected, rightDoor;

	// matrix map
	int map[7][7];

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
