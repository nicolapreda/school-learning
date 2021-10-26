#include <iostream>

using namespace std;

int main() {
	float scelta1, scelta2, scelta3, prezzo;
	cout<<"***********************************************************"<<endl;
	cout<<"*   Tipo  -   Settimanale   -    Mensile    -    Annuale  *"<<endl;
	cout<<"*    1    -     10 euro     -    30 euro    -    250 euro *"<<endl;
	cout<<"*    2    -     5  euro     -    20 euro    -    150 euro *"<<endl;
	cout<<"*    3    -     15 euro     -    40 euro    -    300 euro *"<<endl;
	cout<<"***********************************************************"<<endl;
	cout<<""<<endl;
	cout<<"Gli abboonamenti che non prevedono di viaggiare nelle ore di punta costano il 20 percento in meno"<<endl;
	cout<<endl;
	cout<<"Che tipo di abbonamento scegli? (1, 2, 3)"<<endl;
	cout<<"1) L'abbonamento vale solo per la zona centrale"<<endl;
	cout<<"2) L'abbonamento vale solo per la zona perfiferica"<<endl;
  	cout<<"3) L'abbonamento vale solo per entrambe le zone"<<endl;
	cout<<endl;
  	cin>>scelta1;
	if (scelta1==1){
    	cout<<endl;
    	cout<<"L'abbonamento scelto e' di tipo 1"<<endl;
    	cout<<"Settimanale (1) - Mensile (2) - Annuale (3)"<<endl;
    	cin>>scelta2;
    	cout<<endl;
    if (scelta2==1){
    	cout<<"L'abbonamento scelto e' quello settimanale"<<endl;
    	prezzo=10;
    	cout<<"L'abbonamento prevede il viaggio nelle ore di punta? [si (1) - no (2)]"<<endl;
    	cin>>scelta3;
    	cout<<endl;
    	if(scelta3==1){
			cout<<"Il prezzo per l'abbonamento e': "<<prezzo<<endl;
		}else{
			cout<<"Il prezzo per l'abbonamento e': "<<prezzo*0.8<<endl;
		}
    }else if (scelta2==2){
    	cout<<"L'abbonamento scelto e' quello mensile"<<endl;
    	prezzo=30;
    	cout<<"L'abbonamento prevede il viaggio nelle ore di punta? [si (1) - no (2)]"<<endl;
    	cin>>scelta3;
    	cout<<endl;
    	if(scelta3==1){
        	cout<<"Il prezzo per l'abbonamento e': "<<prezzo<<endl;
      	}else{
        	cout<<"Il prezzo per l'abbonamento e': "<<prezzo*0.8<<endl;
      	}
    }else if (scelta2==3){
    	cout<<"L'abbonamento scelto e' quello mensile"<<endl; 
    	prezzo=250;
    	cout<<"L'abbonamento prevede il viaggio nelle ore di punta? [si (1) - no (2)]"<<endl;
    	cin>>scelta3;
    	cout<<endl;
    	if(scelta3==1){
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo<<endl;
		}else{
        	cout<<"Il prezzo per l'abbonamento e': "<<prezzo*0.8<<endl;
      	}
    }
	}else if (scelta1==2){
    	cout<<endl;
    	cout<<"L'abbonamento scelto e' di tipo 2"<<endl;
    	cout<<"Settimanale (1) - Mensile (2) - Annuale (3)"<<endl;
    	cin>>scelta2;
    	cout<<endl;   
    	if (scelta2==1){
			cout<<"L'abbonamento scelto e' quello settimanale"<<endl;
			prezzo=5;
			cout<<"L'abbonamento prevede il viaggio nelle ore di punta? [si (1) - no (2)]"<<endl;
      		cin>>scelta3;
      		if(scelta3==1){
        		cout<<"Il prezzo per l'abbonamento e': "<<prezzo<<endl;
      		}else{
        		cout<<"Il prezzo per l'abbonamento e': "<<prezzo*0.8<<endl;
      		}
    }else if (scelta2==2){
		cout<<"L'abbonamento scelto e' quello mensile"<<endl;
		prezzo=20;
    	cout<<"L'abbonamento prevede il viaggio nelle ore di punta? [si (1) - no (2)]"<<endl;
    	cin>>scelta3;
    	if(scelta3==1){
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo<<endl;
    	}else{
			cout<<"Il prezzo per l'abbonamento e': "<<prezzo*0.8<<endl;
    	}
    }else if (scelta2==3){
    	cout<<"L'abbonamento scelto e' quello mensile"<<endl; 
    	prezzo=150;
    	cout<<"L'abbonamento prevede il viaggio nelle ore di punta? [si (1) - no (2)]"<<endl;
    	cin>>scelta3;
    	cout<<endl;
    	if(scelta3==1){
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo<<endl;
    	}else{
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo*0.8<<endl;
      	}
    }
	}else if (scelta1==3){   
    	cout<<endl;
    	cout<<"L'abbonamento scelto e' di tipo 3"<<endl;
    	cout<<"Settimanale (1) - Mensile (2) - Annuale (3)"<<endl;
    	cin>>scelta2;
    	cout<<endl;
    if (scelta2==1){
		cout<<"L'abbonamento scelto e' quello settimanale"<<endl;
    	prezzo=15;
    	cout<<"L'abbonamento prevede il viaggio nelle ore di punta? [si (1) - no (2)]"<<endl;
    	cin>>scelta3;
    	if(scelta3==1){
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo<<endl;
    	}else{
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo*0.8<<endl;
      	}
    }else if (scelta2==2){
    	cout<<"L'abbonamento scelto e' quello mensile"<<endl;
    	prezzo=40;
    	cout<<"L'abbonamento prevede il viaggio nelle ore di punta? [si (1) - no (2)]"<<endl;
    	cin>>scelta3;
    	if(scelta3==1){
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo<<endl;
    	}else{
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo*0.8<<endl;
      	}
    }else if (scelta2==3){
    	cout<<"L'abbonamento scelto e' quello mensile"<<endl; 
    	prezzo=300;
    	cout<<"L'abbonamento prevede il viaggio nelle ore di punta? [si (1) - no (2)]"<<endl;
    	cin>>scelta3;
    	if(scelta3==1){
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo<<endl;
    	}else{
    		cout<<"Il prezzo per l'abbonamento e': "<<prezzo*0.8<<endl;
      	}
    }
  	}	
  return 0;
}
