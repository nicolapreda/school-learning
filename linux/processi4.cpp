#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

int main()
{
    pid_t pid;
    //create 4 processes that do 4 different operations
    for (int i = 0; i < 4; i++)
    {
        pid = fork();
        
            //child process
            switch (i)
            {
            case 0:
                cout << "Processo 1 " << getpid() << endl;
                
                break;
            case 1:
                cout << "Processo 2: " << getpid() << endl;
                
                break;
            case 2:
                cout << "Processo 3: " << getpid() << endl;
                
            case 3:
                cout << "Processo 4: " << getpid() << endl;
                break;
            default:
                break;
                
            }
        
        
        
    }
    return 0;
}