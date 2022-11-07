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

int main()
{

    int array[10000];
    int array1[10000];

    srand(time(0));

    for (int x = 0; x < 10000; x++)
    {
        array[x] = rand() * 65536 + rand();
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
    }
    ofstream myfile;
    myfile.open("array");
    for (int i = 0; i < 100000; i++)
    {
        myfile << array[i] << endl;
    }
    myfile.close();

    auto t2 = steady_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "durata: " << duration << endl;

    auto t3 = steady_clock::now();

    int pid = getpid();
    int arr1[5000];
    int arr2[5000];
    // carica arr1 e arr2 con valori casuali con rand
    for (int i = 0; i < 5000; i++)
    {
        arr1[i] = array1[i];
        arr2[i] = array1[i + 5000];
    }

    int pids[2];
    for (int i = 0; i < 4; i++)
    {
        if (getpid() == pid)
            pids[i] = fork();
    }

    if (pid == getppid())
    {
        if (pids[1] == 0)
        {
            for (int i = 0; i < 50000; i++)
            {
                for (int j = 0; j < 50000; j++)
                {
                    if (arr1[i] < arr1[j])
                    {
                        int temp = arr1[i];
                        arr1[i] = arr1[j];
                        arr1[j] = temp;
                    }
                }
            }
            ofstream myfile;
            myfile.open("arr1");
            for (int i = 0; i < 50000; i++)
            {
                myfile << arr1[i] << endl;
            }
            myfile.close();
            exit(0);
        }
        else if (pids[2] == 0)
        {
            for (int i = 0; i < 50000; i++)
            {
                for (int j = 0; j < 50000; j++)
                {
                    if (arr2[i] < arr2[j])
                    {
                        int temp = arr2[i];
                        arr2[i] = arr2[j];
                        arr2[j] = temp;
                    }
                }
            }
            ofstream myfile;
            myfile.open("arr2");
            for (int i = 0; i < 50000; i++)
            {
                myfile << arr2[i] << endl;
            }
            myfile.close();
            exit(0);
        }
    }
    // se invece è ancora il padre crea un altro processo
    else
    {
        waitpid(pids[1], NULL, 0);
        waitpid(pids[2], NULL, 0);
        ifstream myfile;
        myfile.open("arr1");
        for (int i = 0; i < 50000; i++)
        {
            myfile >> arr1[i];
        }
        myfile.close();

        myfile.open("arr2");
        for (int i = 0; i < 50000; i++)
        {
            myfile >> arr2[i];
        }
        myfile.close();

        int arr3[100000];
        int i = 0, j = 0, k = 0;
        while (i < 50000 && j < 50000)
        {
            if (arr1[i] < arr2[j])
            {
                arr3[k] = arr1[i];
                i++;
            }
            else
            {
                arr3[k] = arr2[j];
                j++;
            }
            k++;
        }

        auto t4 = steady_clock::now();

        cout << "\ntempo: " << duration_cast<microseconds>(t4 - t3).count() << " microsecondi" << endl;
    }
}