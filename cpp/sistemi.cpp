#include <iostream>
#include <string>

using namespace std;

struct indirizzo
{
    short int IP[4];
    short int Calcolato[4];
    string dottedDecimal;
    short int bitRete, bitHost;
    string subnetMask;
    string CIDR;
    short int defaultGateway[4];
    short int Broadcast[4];
    short int Rete[4];
    string IPBinario;
    string subBinario;
};

void visualizzaIP(short int ip4[4]);
indirizzo Calcola(short int ip4[4]);
void Mostra(indirizzo IP);

int main()
{
    indirizzo nuovo;
    for (int i = 0; i < 4; i++)
        nuovo.IP[i];

    indirizzo Calcolato = Calcola(nuovo.IP);
}

void visualizzaIP(short int ip4[4])
{
    for (int i = 0; i < 4; i++)
    {
        cout << ip4[i];
        if (i != 3)
            cout << ".";
    }
}

void Mostra(indirizzo IP){
    
    cout<<"IP: ";
}

void Calcola(ip, &nuovo){

}