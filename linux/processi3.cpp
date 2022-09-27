//crea quattro processi figli
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
        int pid = getpid();

        for (int i = 0; i < 4; i++)
        {
            if (getpid() == pid)
            {
                pid = fork();
            }
            
        }
        while(true);
        
    
    return 0;
}