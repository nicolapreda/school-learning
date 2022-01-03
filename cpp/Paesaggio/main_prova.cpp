#include <winbgim.h>
#include <cmath>
int main(){
	//Inizializzo finestra grafica
	initwindow(1024, 768);//Crea una finestra grafica di dimensione 1024, 768
	//vertice alto sinistro coord 0,0
	setlinestyle(0,0,4);\ // Spessore linea
	
	setcolor(COLOR(100,100,255)); //Imposta il colore della penna
	line(0,0,getmaxx(),getmaxy()); // Disegna un segmento tra il punto a e il punto b utilizzando l'attuale penna
	line(0,getmaxy(),getmaxx(),0); // Disegna un segmento tra il punto a e il punto b utilizzando l'attuale penna
	
	int raggio;
	raggio = sqrt(pow((getmaxx() / 2),2) + pow((getmaxy() / 2),2)) / 2;
	setcolor(COLOR(100,100,0));
	circle((getmaxx() / 2),(getmaxy() / 2), raggio);
	setfillstyle(11,COLOR(255,100,0));
	floodfill(getmaxx()/2, getmaxy()/2,COLOR(100,100,0));
	
	arc((getmaxx() / 2), (getmaxy() / 2), 45, 135, 100);	
	rectangle(getmaxx()/2-raggio, getmaxy()/2-raggio,getmaxx()/2+raggio,getmaxy()/2+raggio);
	
	

	getch(); //attende la pressione di un tasto
	return 0;
	
}

/*
		la posizione dell'orizzonte deve essere casuale

		la posizione dell'albero deve essere casuale, 
		   ma all'interno del terreno

		le foglie devono definire la chioma circolare, 
		 il numero, il colore e la dimensione devono essere casuali
		
		la posizione e la dimensione della casa devono essere casuali ma sulla linea
		 dell'orizzonte
		 
		le nuvole devono essere composte da min 2 a un max di 10 cerchi e
		   presenti in numero casuale
	
		i fili d'erba devono essere di sfumenture di verde casuali e devono 
			riempire il terreno fino alla linea dell'orizzonte
			
		
*/