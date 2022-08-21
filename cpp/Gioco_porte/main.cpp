/*
Problema:
  vogliamo gestire un labirinto
  formato da un campo rettangolare
  composto da stanze che presentano 
  4 porte orientate  nei 4 punti cardinali

  Ogni stanza può contenere:
    un certo numero di risorse
    un problema
    un avversario

  Ci sarà una sola stanza di partenza
  e una sola stanza di arrivo

Predisporre la possibilità di creare il labirinto
Creare labirinti casuali
Permettere al giocatore di tentare di uscire dal labirinto


*/
#include <iostream>

const int NORD=0;
const int EST=1;
const int SUD=2;
const int OVEST=3;

const int NESSUN_AVVERARIO=0;
const int MINOTAURO=1;

struct stanza{
  bool porte[4];
  int coin;
  //... risorse
  char problema[256];//se strlen==0 allora nessun problema per la stanza
  char risposta[20];
  int avversario; //tipi di avverario

};

const int DIM_MAX=100;
stanza labirinto[DIM_MAX][DIM_MAX];

int DIM=5;
int posX;
int posY;
/*

void labirinto_random();
stanza crea_stanza();
void crea_labirinto();
bool mossa(int DIR,int &posX,int &posY);
void mostra_stranza(int posX,int posY);
mostra_labirinto();//facoltativa

*/

int main() {
    

  
}