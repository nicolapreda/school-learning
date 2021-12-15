#include <winbgim.h>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Variabili colori
int cielo_giorno = COLOR(138, 196, 255);
int terreno = COLOR(54,36,35);
int tronco_albero = COLOR(46, 39, 24);
int sole_giorno = COLOR(245, 236, 73);
int colore_casa = COLOR(234,193,138);
int porta = COLOR(48,32,3);
int porta_bordi = COLOR(68,46,4);
int nuvola = COLOR(200,255,255);
int tetto = COLOR(227,174,102);
int cielo_notte = COLOR(20,41,97);
int colore_luna = COLOR(245,185,3);
int colore_stelle = COLOR(249,234,172);
int colore_pino = COLOR(31,26,14);

//Define linea orizzonte
int linea_orizzonte = rand() % 200 + 400;

//Funzione riempimento
void riempi(int color1, int riempimento, int x, int y){
		setfillstyle(1,riempimento);
    	floodfill(x,y,color1);
}

void sole(){	//Set Sole
	
	int x_sole = rand() % 900 + 50;
	int y_sole = getmaxy() - linea_orizzonte - 300;
	setcolor(sole_giorno);
	circle (x_sole, y_sole, 100);
	//Riempimento sole
	riempi(sole_giorno, sole_giorno, x_sole, y_sole);

}

void nuvole(){	//Set nuvole
	setcolor(nuvola);
	int n_nuvole = rand() % 7 + 1;
	
	for(int c = 0; c < n_nuvole; c++){
		int xnuvola = rand() % 1400 + 50;
		int ynuvola = rand() % linea_orizzonte + 10;
		ynuvola -= 20;
		int stangle = 0, endangle = 360;
		int xradius = rand() % 50 + 25, yradius = rand() % 30 + 20;
		
		ellipse(xnuvola, ynuvola, stangle, endangle, xradius, yradius);
		riempi(nuvola, nuvola, xnuvola, ynuvola);
		
		ellipse(xnuvola +30, ynuvola + 30, stangle, endangle, xradius, yradius);
		riempi(nuvola, nuvola, xnuvola +30, ynuvola + 50);
		
	}
}


void casa(){	//Set casa
	
	setcolor(colore_casa);
	int x_casa = rand() % 1500 + 50; 
	int h_casa = rand() % 250 + 120;
	int l_casa = rand() % 500 + 200;
	
	rectangle(x_casa, linea_orizzonte - h_casa, x_casa + l_casa,linea_orizzonte);
	riempi(colore_casa, colore_casa, x_casa + 10, linea_orizzonte - 40);
   
	
	setcolor(porta_bordi);	//Set porta
	int x_porta = x_casa + l_casa - (l_casa /2);
	
	rectangle(x_porta - 40, linea_orizzonte - 120, x_porta,linea_orizzonte);
	riempi(porta_bordi, porta,x_porta - 20, linea_orizzonte - 40);
	 
	rectangle(x_porta, linea_orizzonte - 120, x_porta + 40,linea_orizzonte);
	riempi(porta_bordi, porta,x_porta + 10, linea_orizzonte - 40);
	
	setcolor(tetto);	//Set tetto
	int x_tetto = x_casa + l_casa - (l_casa /2);
    line(x_casa, linea_orizzonte - h_casa, x_tetto, linea_orizzonte - h_casa - 70);
    line(x_casa + l_casa, linea_orizzonte - h_casa, x_tetto, linea_orizzonte - h_casa - 70);
    line(x_casa, linea_orizzonte - h_casa, x_casa + l_casa, linea_orizzonte - h_casa);
    
    setfillstyle(1,tetto);
    floodfill(x_tetto, linea_orizzonte - h_casa - 10, tetto);

}

void erba(){	//Set erba
	setlinestyle(0,0,2); // Spessore linea

	for(int c = 0; c < 199999; c++){
		int x_erba = rand() % getmaxx();
		int y_erba = rand() % getmaxy() + (linea_orizzonte - 5);
		int colore_erba = rand() % 150;
		int lunghezza_erba = rand() % 5;
		setcolor(COLOR(0,colore_erba,0));
		//Set arco erba
		line(x_erba, y_erba, x_erba + rand() % 5 + 1, y_erba + lunghezza_erba);
		//arc(x_erba, y_erba, x_erba, y_erba + lunghezza_erba, 2);
	}
}

void albero(){	//Set albero
	srand (time(0));
	int n_alberi = rand() % 4 + 1;
	cout<<n_alberi;
	for(int n = 0; n < n_alberi; n++){
			setcolor(COLOR(108,54,0));
	    int xtronco=rand()%getmaxx();
		int ytronco=rand()%(getmaxy()-linea_orizzonte);
		int htronco=rand()%110+110;
		int ltronco=rand()%35+35;
		rectangle(xtronco-ltronco/2,linea_orizzonte+ytronco,xtronco+ltronco/2,linea_orizzonte+ytronco-htronco);
		
		setfillstyle(1,COLOR(108,54,0));
		floodfill(xtronco,linea_orizzonte+ytronco-htronco/2,COLOR(108,54,0));
			
		
		int hchioma = rand()%100+200;	//Set chioma
		int xchioma = xtronco;
		int ychioma = linea_orizzonte+ytronco-htronco-hchioma/2;
			
		for(int foglie=0;foglie<1000;foglie++){	//Set foglie
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
	}
	
	
}
void stelle(){	//Set stelle
	
	setcolor(colore_stelle);
	for(int stelle = 0; stelle < 1000; stelle++){
		
		int x_stella = rand() % getmaxx();
		int y_stella = rand() %linea_orizzonte;
		circle(x_stella, y_stella, rand() % 2);
		
	}
	
}

void luna(){	//Set luna
	srand (time(0));
	//Set Luna
	int x_luna = rand() % 700 + 100;
	int y_luna = getmaxy() - linea_orizzonte - 300;
	setcolor(colore_luna);
	circle (x_luna, y_luna, 100);
	//Riempimento luna
	riempi(colore_luna, colore_luna, x_luna, y_luna);
	
	setcolor(cielo_notte);
	circle (x_luna - 100, y_luna, 100);
	riempi(cielo_notte, cielo_notte, x_luna - 100, y_luna);
}


void giorno(){
	setcolor(terreno);
	setlinestyle(0,0,4); // Spessore linea
	
	line(0,linea_orizzonte,getmaxx(),linea_orizzonte);
	//Colore cielo
	riempi(terreno, cielo_giorno,0,0);
	//Colore terreno
	riempi(terreno, porta,getmaxx(),getmaxy());
	
	
	//Imposta sole
	sole();
	//Imposta nuvole
	nuvole();
	//Imposta casa
	casa();	
	//Imposta erba
	erba();
	//Imposta albero
	albero();
	
}

void notte(){
	
	setcolor(terreno);
	setlinestyle(0,0,4); // Spessore linea
	
	line(0,linea_orizzonte,getmaxx(),linea_orizzonte);
	//Colore cielo
	riempi(terreno, cielo_notte,0,0);
	//Colore terreno
	riempi(terreno, porta,getmaxx(),getmaxy());
	
	stelle();
	luna();
	
	//Imposta casa
	casa();	
	//Imposta erba
	erba();
	//Imposta albero
	albero();

}

	
int main(){	

	srand (time(0));
	//Inizializzo finestra grafica
	initwindow(1600,900);
	
	short int time = rand() % 2;
	
	switch(time){
		case 0:
			notte();
			break;
		case 1:
			giorno();
			break;
		
	}

	getch();
	return 0;
}
