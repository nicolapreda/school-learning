/*
Crea un programma c++ che, letti da riga di comando 2 argomenti, generi 4 figli che svolgano e restituiscano il risultato delle operazioni di somma, differenza, prodotto e divisione.
Il processo padre scriverà a video il risultato.

*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[])
{
    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);
    int status;
    int pid = getpid();

    for(int i=0; i<4; i++){
        fork();
        if(getpid()!= pid){
            if (i==0)
            {
                exit(arg1+arg2);
            }else if(i==1){
                exit(arg1-arg2);
            }else if(i==2){
                exit(arg1*arg2);
            }else if(i==3){
                exit(arg1/arg2);
            }
            else{
                wait(&status);
                int exit_status = WEXITSTATUS(status);
              //scrive lo stato in usc  
                cout << "Figlio: " << i+1 << ": " << exit_status << endl;
                
            }
            
        }
    }

    return 0;
}