#include <iostream>

using namespace std;

int main()
{
    /*
    Scrivere un programma in C++ che descrivere la seguente situazione:
    Uno scalatore deve scalare il Gran Sasso (2912 metri) e vogliamo sapere quanto tempo ci mette.
    Nel dettaglio nel programma bisogna chiedere all'utente da che quota parte lo scalatore e 
    per quanti giorni ha cibo a disposizione.
    Lo scalatore non percorre ogni giorni la stessa distanza, ma un giorno riesce a scalare 100 
    metri, il giorno dopo 50 metri, il giorno dopo ancora di nuovo 100 metri e così via.
    Inoltre, se lo scalatore raggiunge la vetta in un tempo maggiore rispetto ai giorni per cui 
    ha cibo a disposizione il programma deve stampare un messaggio che informa del fatto che lo 
    scalatore non può sopravvivere alla scalata.
    */

    int quota_iniziale, g_cibo, quota_totale = 2912, giorni;
    cout<<"Quota iniziale: ";
    cin>>quota_iniziale;
    cout<<"Giorni di cibo: ";
    cin>>g_cibo;

    for (giorni = 1; quota_iniziale < quota_totale; giorni++)
    {
        if (giorni % 2 == 0)
            quota_iniziale += 100;
        else
            quota_iniziale += 50;
        
        g_cibo--;
        
        
    }
    
    if(g_cibo<=0)
        cout<<"Lo scalatore non potrà sopravvivere alla scalata."<<endl;

    cout<<"Lo scalatore ha raggiunto la quota finale dopo "<<giorni<<" giorni."<<endl;
}