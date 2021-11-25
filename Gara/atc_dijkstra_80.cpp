/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <list>
#include <set>

using namespace std;

// constraints
#define MAXN 200

#define INF 1000000

struct Arco_orientato{
 int nodo_destinazione;
 int peso;
 Arco_orientato(int a, int b):nodo_destinazione(a), peso(b){};
};

 struct Nodo{
     list <Arco_orientato> archi;
     int distanza;
     int precedente;
     Nodo():precedente(-1),distanza(INF){};
 };

 Nodo nodi[MAXN*MAXN];
 set <int> stabili;
 //int N,M;

 int dijkstra(int da, int a, int n_nodi)
 {
    int minimo = 0;
    nodi[da].distanza = 0;
    stabili.insert(da);
    Nodo nodo_corrente = nodi[da];
    int ultimo_inserito = da;
    while (stabili.size() != n_nodi && minimo<INF)
    {
        //printf("%d ", stabili.size());
        list <Arco_orientato>::iterator i = nodo_corrente.archi.begin();
        for(;i!=nodo_corrente.archi.end();++i)
         {
             int nodo_da_aggiornare = i->nodo_destinazione;
             if (nodi[nodo_da_aggiornare].distanza > nodi[ultimo_inserito].distanza + i->peso)
             {
                 nodi[nodo_da_aggiornare].distanza = nodi[ultimo_inserito].distanza + i->peso;
                 nodi[nodo_da_aggiornare].precedente = ultimo_inserito;
             }
         }
         minimo = INF;
         for (int i = 0; i < n_nodi; i++)
         {
            if (stabili.find(i) == stabili.end() && nodi[i].distanza < minimo)
             {
                minimo = nodi[i].distanza;
                ultimo_inserito = i;
             }
         }
         nodo_corrente = nodi[ultimo_inserito];
         stabili.insert(ultimo_inserito);
     }
     return nodi[a].distanza;
 }



// input data
int N, i;
char grid[MAXN][MAXN + 1];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%s", grid[i]));
    /*
    printf("dati letti %d\n", N);
    for (int x=0; x<N; x++){
        for (int y=0; y<N; y++)
            printf("%c", grid[x][y]);
        printf("\n");
    }
    */
    // insert your code here
    int towers = -1;
    //ciclo su matrice mappa e ricavo archi
    for (int x=0; x<N; x++){
        for (int y=0; y<N; y++){
            if (grid[x][y]!='#'){
                //archi a destra
                i=y+1;
                while(i<N && grid[x][i]!='#'){
                    Arco_orientato temp(x*N+i,1);
                    nodi[x*N+y].archi.push_back(temp);
                    i++;
                }
                //archi in basso
                i=x+1;
                while(i<N && grid[i][y]!='#'){
                    Arco_orientato temp(i*N+y,1);
                    nodi[x*N+y].archi.push_back(temp);
                    i++;
                }
                //archi a sinistra
                i=y-1;
                while(i>=0 && grid[x][i]!='#'){
                    Arco_orientato temp(x*N+i,1);
                    nodi[x*N+y].archi.push_back(temp);
                    i--;
                }
                //archi in alto
                i=x-1;
                while(i>=0 && grid[i][y]!='#'){
                    Arco_orientato temp(i*N+y,1);
                    nodi[x*N+y].archi.push_back(temp);
                    i--;
                }
            }
        }
    }
    /*
    printf("grafo creato %d\n", N);
    for(int k=0;k<N*N-1;k++){
        list <Arco_orientato>::iterator it = nodi[k].archi.begin();
        for(;it!=nodi[k].archi.end();++it)
        {
            printf("%d,", it->nodo_destinazione);
        }
        printf("\n");
    }
    */
    dijkstra(0,N*N-1,N*N);
    if (nodi[N*N-1].distanza<INF)
        towers=nodi[N*N-1].distanza-1;
    printf("%d\n", towers);
        return 0;
    }



