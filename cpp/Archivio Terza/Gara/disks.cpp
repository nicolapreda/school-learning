// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
   
    int Inizio, Fine, Ore_n, InizioRip;
    
    Inizio = 7;
    Fine = 21;
    Ore_n = 42;
    int ore_attivita = Fine - Inizio;
    int ore_inattivita = 24 - ore_attivita;

    //Trovo le ore iniziali (3)
    int ore_iniziali = 24 - Fine;
    
    int giorni_necessari = Ore_n / 24;
    int ore_rimanenti = Ore_n % 24;
    
    int ore_finali = ore_rimanenti - ore_attivita;

    int output = Ore_n - (ore_inattivita * giorni_necessari)- (ore_rimanenti - ore_inattivita);
    
   

    cout<<endl<<endl<<output<<endl;

    return 0;
}