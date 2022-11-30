#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fstream>

using namespace std;
using std::chrono::steady_clock;
using std::chrono::system_clock;
using namespace std::chrono;

int main(int argc, char *argv[])
{
    //salvo nella variabile intera n il numero in input
    int n = atoi(argv[1]);
    //salvo nella variabile pid il Process ID del padre
    int pid = getpid();
    //variabile status per i processi figli
    int status;

    // creo due figli che caricano metà array ciascuno
    for (int i = 0; i < 2; i++)
    {

        fork();
        srand(getpid());
        if (getpid() != pid)
        {
            //divido l'array e trovo in modo random il suo contenuto (numeri compresi tra -128 e 127)
            int array[n / 2];
            for (int i = 0; i < n / 2; i++)
            {
                array[i] = (rand() % 256) - 128;
            }
            // scrivo contenuto array su file
            ofstream myfile;
            myfile.open("array", std::ios::out | std::ios::app);

            for (int i = 0; i < n / 2; i++)
            {
                myfile << array[i] << endl;
            }

            myfile.close();
            exit(0);
        }
    }

    //aspetto che tutti e due i processi figli finiscano
    for (int i = 0; i < 2; i++)
    {
        wait(&status);
    }

    //parte il timer per calcolare il tempo impiegato dai processi a calcolare il minimo e il massimo dell'array
    auto t1 = steady_clock::now();

    // carico array dal file
    int array[n];
    ifstream myfile;
    myfile.open("array");
    for (int i = 0; i < n; i++)
    {
        myfile >> array[i];
    }
    myfile.close();

    // rimuovo il file array
    remove("array");

    // stampo a video il comtenuto dell'array
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    // creo due processi separati per il minimo e il massimo
    int pids[2];
    for (int i = 0; i < 2; i++)
    {
        if (getpid() == pid)
        {
            pids[i] = fork();
        }
    }

    if (pid == getppid())
    {
        // trovo il minimo con il primo processo

        if (pids[0] == 0)
        {
            int min = array[0];
            for (int i = 0; i < n; i++)
            {
                if (array[i] < min)
                {
                    min = array[i];
                }
            }
            // ritorno in uscita il valore min + 128 (non può restituire valori negativi)
            exit(min + 128);
        }
        // trovo il massimo con il secondo processo
        if (pids[1] == 0)
        {
            int max = array[0];
            for (int i = 0; i < n; i++)
            {

                if (array[i] > max)
                {
                    max = array[i];
                }
            }

            // ritorno in uscita il valore max + 128 (non può restituire valori negativi)

            exit(max + 128);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        // attendo che i figli finiscano
        waitpid(pids[i], &status, 0);
        if (i == 0)
            // stampo a video il valore min - 128
            cout << "Min: " << WEXITSTATUS(status) - 128 << endl;
        else
            // stampo a video il valore max - 128
            cout << "Max: " << WEXITSTATUS(status) - 128 << endl;
    }


    auto t2 = steady_clock::now();
    //calcolo il tempo impiegato dal programma per il calcolo del minimo e massimo con chrono
    auto duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Durata in microsecondi: " << duration << endl;
}