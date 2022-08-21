/*file navi.txt contiene una mappa 
di dimensione 10x10 sulla quale sono 
disposte 3 navi (una da tre elementi, 
una da due e una da uno)*/

#include <iostream>
#include <fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;

int main(){
      srand (time(NULL));
    int matrix[10][10];
    	fstream gridFile;
	gridFile.open("Navi.txt", fstream::out);
	for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
                matrix[y][x] = rand() % 5;
                gridFile << matrix[y][x]<< " ";

        }
        gridFile<<endl;
        
    }
    
    gridFile.close();
    return 0;
}