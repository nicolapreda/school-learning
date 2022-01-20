#include <iostream>
#include <time.h>
#include <vector> 
using namespace std;

int main() {
  //Generatore sequenze e colori casuali
  srand(time(0));
  
  short int lSequenza, seqNumeri, mode;
  cout<<"Corrispondente colori:"<<endl;
  cout<<"0=>Bianco"<<endl;
  cout<<"1=>Verde"<<endl;
  cout<<"2=>Blu"<<endl;
  cout<<"3=>Viola"<<endl;
  cout<<"4=>Arancione"<<endl;
  cout<<"5=>Verde Chiaro"<<endl;
  cout<<"6=>Rosso"<<endl;
  cout<<"7=>Rosso"<<endl;
  cout<<"8=>Rosso"<<endl;
  cout<<"9=>Rosso"<<endl;

  

  //Creazione lunghezza sequenza
  do{
    cout<<"Scegli una sequenza da 4 a 6.:"<<endl;
    cin>>lSequenza;
  }while(lSequenza<4 || lSequenza>6);

  //Selezione della modalita
  do{
    cout<<"Scegli la modalità(0=>Facile \n 1=>Standard \n 2=>Difficile)"<<endl;
    cin>>mode;
  }while(mode<0 || mode>2);
  
  //Creazione colori possibili
  do{
    cout<<"Scegli i colori possibili (da 4 a 10)"<<endl;
    cin>>seqNumeri;
  }while(seqNumeri<4 || seqNumeri>10);
  
  //Creazione sequenza casuale
  int sequenzaGenerata[lSequenza];
  for(int c=0; c<lSequenza; c++){
      sequenzaGenerata[c]=rand()%seqNumeri;  
      cout<<sequenzaGenerata[c];
  }
  //Contiene la sequenza corrente scelta dall'utente
  int sequenzaCorrente[lSequenza];
  bool corretta = true;
  
  //For tentativi
  for(int tentativi=10; tentativi>0; tentativi--){
    cout<<"Hai"<<tentativi<<"tentativi!"<<endl;
    for(int seq=0; seq<lSequenza; seq++){
      cout<<"Inserisci un numero (corrispondente a un colore)"<<endl;
      cin>>sequenzaCorrente[seq];
    }
  //Verifica se è uguale alla sequenza iniziale
  switch (mode){
    /*Modalita facile: posso vedere le posizioni corrette con il colore corretto e le posizioni sbagliate ma con il colore corretto*/
    case 0:
      for(int nVerifica=0; nVerifica<lSequenza; nVerifica++){
          
          if(sequenzaCorrente[nVerifica] != sequenzaGenerata[nVerifica]){ 
            corretta = false; 
            if (includes(begin(sequenzaCorrente), end(sequenzaCorrente),
                  begin(sequenzaGenerata), end(sequenzaGenerata))
            {

            // array2 includes array1
            
            }
          }else{
            cout<<"Posizione e colore corretto\n";
          }
        

      }
      break;
      case 1:
      break;
      case 2:
      break;
  }
  
    
    if(corretta==true){
      cout<<"COMPLIMENTI, HAI VINTOOOO!"<<endl;
      return 0;
    }else{
      corretta=true;
    }

  }

  cout<<"Hai perso!"<<endl;

} 