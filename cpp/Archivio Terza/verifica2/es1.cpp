#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAX = 100;

void genVoti(int registro[MAX][MAX], int nVoti, int nStud);
void media(int registro[MAX][MAX], int nVoti, int nStud);

int main() {
	
	srand(time(0));
	
	int registro[MAX][MAX];
	
	int nVoti, nStud;
	
	cout<<"Inserisci numero studenti: ";
	cin>>nStud;
	
	cout<<"Inserisci numero voti: ";
	cin>>nVoti;
	
	genVoti(registro, nVoti, nStud);
	media(registro, nVoti, nStud);

	return 0;
}

void genVoti(int registro[MAX][MAX], int nVoti, int nStud){
	
	for(int i=0; i<nStud; i++){
		for(int k=0; k<nVoti; k++){
			registro[i][k] = rand()%8+3;
			cout<<registro[i][k]<<"\t";
		}
		
		cout<<endl;
	
	}
	
	
}

void media(int registro[MAX][MAX], int nVoti, int nStud){
	
	int somma = 0;
	int mediaInt; 
	double media;
	
	for(int i=0; i<nStud; i++){
		for(int k=0; k<nVoti; k++){
			somma += registro[i][k];
		}
		
		mediaInt = (float(somma)/nVoti)*100;
		media = float(mediaInt) / 100;
		cout<<"Studente "<<i+1<<" ha la media: "<<media;
		
		
		cout<<endl;
		somma = 0;

	
	}	
	
}




