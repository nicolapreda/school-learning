/* Scrivere un programma in c++ che permetta la creazione di un processo figlio 
che resta in esecuzione in memoria mentre il processo padre che lo ha creato dopo 
aver scritto il proprio process id e il process id del processo padre che lo ha creato termina */
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    pid_t pid;
    pid = fork();
    sleep(1);
    if (pid == 0)
    {
        cout << "Sono il processo figlio con PID " << getpid() << endl;
        cout << "Il processo del padre: " << getppid() << endl;
        
    }
    else
    {
        cout << "Processo padre: " << getpid() << endl;
    }
    return 0;
}

//get pid => pid
//get ppid => pid del padre