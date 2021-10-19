#include <iostream>

using namespace std;

int main(){
    int spessore_finale, spessore_iniziale, n_laminatoi, percent;
    /* Determina il numero di laminatoi necessari per ottenere un laminato di spessore definito */
    do{
    cout<<"Inserisci lo spessore iniziale del laminato (mm) "<<endl;
    cin>>spessore_iniziale;
    } while (spessore_iniziale <= 0);
    
    do{
    cout<<"Inserisci lo spessore finale desiderato (mm)"<<endl;
    cin>>spessore_finale;
    } while (spessore_finale < 0 || spessore_finale > spessore_iniziale);

    while (spessore_iniziale != spessore_finale)
    {
        percent = spessore_iniziale * 10 / 100;
        spessore_iniziale = spessore_iniziale - percent;
        n_laminatoi++;
    }
    
    cout<<"Laminatoi necessari: "<<n_laminatoi<<endl;
    return main();

}