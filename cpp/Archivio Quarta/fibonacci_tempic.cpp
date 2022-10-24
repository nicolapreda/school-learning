#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;


long long fib(long long n){
	if (n==0)
		return 1;
	if (n==1)
		return 1;
	return fib(n-1)+fib(n-2);
}




int main()
{
	
	clock_t start,end;
	double tempo;
    for (int numero = 1; numero <= 20; numero++)
    {

//apri un file in scrittura
ofstream output("risultati.txt");

        cout<< numero<< ": ";
         

        start=clock();
        fib(numero);
        end=clock();
        tempo=((double)(end-start))/CLOCKS_PER_SEC;
        cout<<tempo<<" sec"<<endl;
        
        
        
        output.close();

    }	
}