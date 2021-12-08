#include <winbgim.h>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


void riempi(int color1, int riempimento, int x, int y){
		setfillstyle(0,riempimento);
    	floodfill(x,y,color1);
}
	
	
int main(){
	
	
	//Variabili colori
	const int cielo_giorno = COLOR(138, 196, 255);
	const int terreno = COLOR(54,36,35);
	const int tronco_albero = COLOR(46, 39, 24);
	const int sole_giorno = COLOR(245, 236, 73);
	const int casa = COLOR(182,33,33);
	const int porta = COLOR(48,32,3);
	const int porta_bordi = COLOR(68,46,4);
	const int nuvole = COLOR(200,255,255);
	const int tetto = COLOR(255,127,39);
	
	//Inizializzo finestra grafica
	initwindow(1600,900);
	
	srand (time(0));
	
	/*Set linea orizzonte*/	
	int linea_orizzonte = rand() % 200 + 400;
	
	setcolor(terreno);
	setlinestyle(0,0,4); // Spessore linea
	
	line(0,linea_orizzonte,getmaxx(),linea_orizzonte);
	
	/*Set cielo*/
	setfillstyle(1,cielo_giorno);
	floodfill(0, 0,terreno);
	//Set Sole
	int x_sole = rand() % 900 + 50;
	int y_sole = getmaxy() - linea_orizzonte - 300;
	setcolor(sole_giorno);
	circle (x_sole, y_sole, 100);
	
	setfillstyle(1,sole_giorno);
	floodfill(x_sole , y_sole +80,sole_giorno);
	
	//Set nuvole
	setcolor(nuvole);
	int n_nuvole = rand() % 5 + 1;
	for(int c = 0; c < n_nuvole; c++){
		int xnuvola = rand() % 1500 + 50;
		int ynuvola = rand() % linea_orizzonte;
		circle (xnuvola, ynuvola,rand() % 60 + 10);
		setfillstyle(1,nuvole);
    	floodfill(xnuvola , ynuvola, nuvole);
    	
		circle (xnuvola + 30, ynuvola + 30,rand() % 60 + 10);
		setfillstyle(1,nuvole);
    	floodfill(xnuvola + 30 , ynuvola + 30, nuvole);
	}
			
	//Casa
	setcolor(casa);
	int x_casa = rand() % 1500 + 50;
	int h_casa = rand() % 300 + 50;
	int l_casa = rand() % 500 + 200;
	
	rectangle(x_casa, linea_orizzonte - h_casa, x_casa + l_casa,linea_orizzonte);

	setfillstyle(1,COLOR(182,33,33));
    floodfill(x_casa + 10, linea_orizzonte - 40, COLOR(182,33,33));
    
	//Porta
	setcolor(porta_bordi);
	int x_porta = x_casa + l_casa - (l_casa /2);
	
	rectangle(x_porta - 40, linea_orizzonte - 120, x_porta,linea_orizzonte);
	setfillstyle(1,porta);
    floodfill(x_porta - 20, linea_orizzonte - 40, porta_bordi);
    
	rectangle(x_porta, linea_orizzonte - 120, x_porta + 40,linea_orizzonte);
	setfillstyle(1,porta);
    floodfill(x_porta + 10, linea_orizzonte - 40, porta_bordi);
	
    
	//Tetto
	setcolor(tetto);
	int x_tetto = x_casa + l_casa - (l_casa /2);
    line(x_casa, linea_orizzonte - h_casa, x_tetto, linea_orizzonte - h_casa - 70);
    line(x_casa + l_casa, linea_orizzonte - h_casa, x_tetto, linea_orizzonte - h_casa - 70);
    line(x_casa, linea_orizzonte - h_casa, x_casa + l_casa, linea_orizzonte - h_casa);
    
    setfillstyle(1,tetto);
    floodfill(x_tetto, linea_orizzonte - h_casa - 10, tetto);
    
    
	//Erba
	for(int c = 0; c < 100000; c++){
		int x_erba = rand() % getmaxx();
		int y_erba = rand() % getmaxy() + (linea_orizzonte - 5);
		int colore_erba = rand() % 150;
		int lunghezza_erba = rand() % 5;
		setcolor(COLOR(0,colore_erba,0));
		//Set arco erba
		arc(x_erba, y_erba, x_erba, y_erba + lunghezza_erba, 2);
	}
	//Albero
	setcolor(COLOR(108,54,0));
    int xtronco=rand()%getmaxx();
    int ytronco=rand()%(getmaxy()-linea_orizzonte);
    int htronco=rand()%110+110;
    int ltronco=rand()%35+35;
    rectangle(xtronco-ltronco/2,linea_orizzonte+ytronco,xtronco+ltronco/2,linea_orizzonte+ytronco-htronco);
    setfillstyle(1,COLOR(108,54,0));
    floodfill(xtronco,linea_orizzonte+ytronco-htronco/2,COLOR(108,54,0));
	
	//Chioma
	int hchioma = rand()%100+200;
	int xchioma = xtronco;
	int ychioma = linea_orizzonte+ytronco-htronco-hchioma/2;
	
	
	//Foglie
	for(int foglie=0;foglie<1000;foglie++){
        int xfoglia=xchioma+rand()%hchioma-hchioma/2;
        int yfoglia=ychioma+rand()%hchioma-hchioma/2;
        if (sqrt((xchioma-xfoglia)*(xchioma-xfoglia)+(ychioma-yfoglia)*(ychioma-yfoglia))<hchioma/2){
        	int f_color = rand() % 205 + 50;
			setcolor(COLOR(0,f_color,0));
			circle(xfoglia,yfoglia,rand()%20+10);   	
        	setfillstyle(0,COLOR(0,193,49));
        	floodfill(xfoglia,yfoglia,COLOR(0,193,49));
		}
	}
		
	
	getch();
	return 0;
}
