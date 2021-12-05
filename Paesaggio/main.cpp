#include <winbgim.h>
#include <cmath>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>      /* time */

using namespace std;

int main(){
	//Colori
	const int cielo_giorno = COLOR(138, 196, 255);
	const int erba_giorno = COLOR(0, 255, 183);
	const int tronco_albero = COLOR(46, 39, 24);
	const int sole_giorno = COLOR(245, 236, 73);
	
	//Inizializzo finestra grafica
	initwindow(1024, 768);//Crea una finestra grafica di dimensione 1024, 768
	
	srand (time(0));
	
	/*Set linea orizzonte*/	
	short int linea_orizzonte = rand() % 400 + 150;
	setcolor(COLOR(0,255,0));
	setlinestyle(0,0,4); // Spessore linea
	line(0,getmaxy() - linea_orizzonte,getmaxx(),getmaxy() - linea_orizzonte);
	
	
	/*Set cielo*/
	setfillstyle(1,cielo_giorno);
	floodfill(0, 0,COLOR(0,255,0));
		
	/*Set erba*/
	setfillstyle(1,erba_giorno);
	floodfill(getmaxx(), getmaxy(),COLOR(0,255,0));

	/*Set Sole*/
	int x_sole = rand() % 900 + 50;
	int y_sole = getmaxy() - linea_orizzonte - 300;
	setcolor(sole_giorno);
	circle (x_sole, y_sole, 100);
	
	setfillstyle(1,sole_giorno);
	floodfill(x_sole , y_sole,sole_giorno);
	
	
	/*Set albero*/
	
	int x_albero = rand() % 900 + 50;
	int y_albero = rand() % linea_orizzonte + getmaxx();
	
	setcolor(tronco_albero);
	rectangle(x_albero, y_albero - 200, x_albero + 50, y_albero);
	
	//setfillstyle(1,tronco_albero);
	//floodfill(x_albero + 10 , y_sole,tronco_albero);
	
	/*Set foglie*/
	/*
	int y_foglie = y_albero + 500;
	int x_foglie = (x_albero + x_albero + 50) / 2;
	circle(x_foglie, y_foglie + 50, 50);
	*/	
	
	/*Set casa
	setcolor(COLOR(186, 68, 52));
	int x_casa = rand() % 900 + 50;
	int y_casa = rand() % 300;
	rectangle(x_casa, y_casa + 600, x_albero + 600, getmaxy() - linea_orizzonte - y_casa);*/

	
	getch(); //attende la pressione di un tasto
	return 0;
}
