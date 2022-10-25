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
using std::chrono::system_clock;
using std::chrono::steady_clock;
using namespace std::chrono;

int main()
{


    long long int array[10000];
    long long int array1[10000];

    srand(time(NULL));

    for (int x = 0; x < 10000; x++)
    {
        array[x] = rand() % 2000000000;
        array1[x] = array1[x];
    }

    auto t1 = steady_clock::now();
    // ordinamento bubble sort e stampa elementi array
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000 - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }

        cout << array[i] << "\t";
    }
    
    cout<<endl;
    auto t2 = steady_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count();
    cout<<"durata: "<< duration<<endl; 

    

    auto t3 = steady_clock::now();

    int arr1[5000];
    int arr2[5000];
    //carica arr1 e arr2 con valori casuali con rand
    for (int i = 0; i < 5000; i++)
    {        arr1[i] = array[i];
        
    }
    for (int i = 0; i < 5000; i++)
    {
        arr2[i] = array[i+5000];
    }
    
    int pid = fork();
    //se è il figlio ordina arr1
    if (pid == 0)
    {
        //apri file array1.txt per scrivere
        ofstream file1;
        file1.open("array1.txt");
        for (int i = 0; i < 5000; i++)
        {
            for (int j = 0; j < 5000; j++)
            {
                if (arr1[i] < arr1[j])
                {
                    int temp = arr1[i];
                    arr1[i] = arr1[j];
                    arr1[j] = temp;
                }
            }
            
        }
    }
    //se invece è ancora il padre crea un altro processo
    else
    {
        int pid2 = fork();
        //se è il figlio ordina arr2
        if (pid2 == 0)
        {
            for (int i = 0; i < 5000; i++)
            {
                for (int j = 0; j < 5000; j++)
                {
                    if (arr2[i] < arr2[j])
                    {
                        int temp = arr2[i];
                        arr2[i] = arr2[j];
                        arr2[j] = temp;
                    }
                }
                cout << array[i] << "\t";
            }
            cout<<endl;
        }
        //se invece è ancora il padre aspetta che i figli finiscano
        else
        {
            waitpid(pid, NULL, 0);
            waitpid(pid2, NULL, 0);
        }
    }

    auto t4 = steady_clock::now();



}