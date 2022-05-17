#include <iostream>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct Utente{
	
	char cognome[30];
	long long int numeri[5] = { 0, 0, 0, 0, 0};
	
	
};

const int MAX = 100;

void ricercaCognome(Utente rubrica[MAX], int utenti, char cognome[30]);

int main() {

	Utente rubrica[MAX];
	
	int utenti;
	int numeri;
	
	cout<<"Inserisci numero utenti da aggiungere: ";
	cin>>utenti;
	
	for(int i=0; i<utenti; i++){
						
		cout<<"Inserisci cognome: ";
		cin>>rubrica[i].cognome;
		
		cout<<"Inserisci quanti numeri aggiungere massimo 5: ";
		cin>>numeri;
		
		cout<<"Inserisci i Numeri: "<<endl;
		for(int k=0; k<numeri; k++){
			cin>>rubrica[i].numeri[k]; 
		}
		
	}
	
	char cognome[30];
	
	cout<<"Inserisci cognome da cercare: ";
	cin>>cognome;	
	ricercaCognome(rubrica, utenti, cognome);
	
	
	return 0;
}

void ricercaCognome(Utente rubrica[MAX], int utenti, char cognome[30]){
	
	cout<<"I numeri di "<<cognome<<" sono: "<<endl;
	
	for(int i=0; i<utenti; i++){
		
		if(strcmp(cognome,rubrica[i].cognome) == 0){
			
			for(int k=0; k<5; k++){
				
				if(rubrica[i].numeri[k] != 0){
					cout<<rubrica[i].numeri[k]<<endl;	
				}
				
			}
					
		}
		
	}
	
}