// scrive dopo che il figlio è determinato il processo id del padre continuamente per controllare se il padre è ancora vivo

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{

    int pid = fork();
    int ppid = getppid();

        if (ppid != 0)
        {
            for(int i = 0; i < 20; i++)
            cout << "il processo padre è ancora vivo " << ppid << endl;
        }
        else
        {
            while (ppid == getppid())
            {
                cout << "Sono orfano " << ppid << endl;
            }
        }
    
    return 0;
}