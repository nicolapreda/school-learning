/*il processo padre scrive il proprio PID, il PID del processo che lo ha generato e il PID del processo figlio, poi termina
 il processo figlio scrive per PRIMO il proprio PID e il PID del processo padre, attende la morte del padre e riscrive le stesse informazioni per poi terminare
*/
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    pid_t pid;
    pid = fork();
    
    if (pid != 0)
    {
        sleep(1);
        cout << "Sono il processo figlio con PID " << getpid() << endl;
        cout << "Il processo del padre: " << getppid() << endl;
    }
    else
    {
        cout << "Processo figlio: " << getpid() << endl;
        cout << "Processo padre: " << getppid() << endl;
        sleep(1);
        cout << "Processo figlio: " << getpid() << endl;
        cout << "Processo padre: " << getppid() << endl;
    }
    return 0;
}