#include <iostream>

using namespace std;

int main(){
    int laminatoi, spessore, dim_spessore;
    /* Serie di n laminatoi che diminuiscono lo spessore del 10% */
    do{
    cout<<"Inserisci lo spessore iniziale del laminato (mm) "<<endl;
    cin>>spessore;
    } while (spessore <= 0);
    
    do{
    cout<<"Inserisci il numero di laminatoi presenti nel processo di lavorazione"<<endl;
    cin>>laminatoi;
    } while (laminatoi < 0);

    while (laminatoi > 0)
    {
        dim_spessore = spessore * 10 / 100;
        spessore = spessore - dim_spessore;
        laminatoi--;
    }
    
    cout<<"Spessore del laminato: "<<spessore<<"mm"<<endl;
    return main();

}