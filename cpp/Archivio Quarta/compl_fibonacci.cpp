#include <iostream>
#include <time.h>

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
    for (int numero = 1; numero <= 54; numero++)
    {
        cout<< numero<< ": ";
        start=clock();
        fib(numero);
        end=clock();
        tempo=((double)(end-start))/CLOCKS_PER_SEC;
        cout<<tempo<<" sec"<<endl;

    }	
}