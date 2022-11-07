#include <iostream>
#include <sys/types.h>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <chrono>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fstream>
using namespace std;
using std::chrono::steady_clock;
using std::chrono::system_clock;
using namespace std::chrono;

int main()
{
    int arr[100000], status;
    srand(time(0));

    for (int i = 0; i < 100000; i++)
    {
        arr[i] = rand() * 65536 + rand();
    }
    int arr2[100000];
    for (int i = 0; i < 100000; i++)
    {
        arr2[i] = arr[i];
    }

#pragma region BubbleSort_single
    auto t1 = steady_clock::now();
    for (int i = 0; i < 100000; i++)
    {
        for (int j = 0; j < 100000; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    ofstream myfile;
    myfile.open("arr");
    for (int i = 0; i < 100000; i++)
    {
        myfile << arr[i] << endl;
    }
    myfile.close();
    auto t2 = steady_clock::now();
    /*for(int i=0;i<10000;i++){
        cout << arr[i] << " ";
    }*/
    cout << "\nTempo di esecuzione: " << duration_cast<microseconds>(t2 - t1).count() << " microsecondi" << endl;
#pragma endregion

    int arr3[50000];
    int arr4[50000];
    for (int i = 0; i < 50000; i++)
    {
        arr3[i] = arr2[i];
        arr4[i] = arr2[i + 50000];
    }

    int pid = getpid(), pids[2];
    for (int i = 0; i < 4; i++)
    {
        if (getpid() == pid)
            pids[i] = fork();
    }

    auto t3 = steady_clock::now();
    if (getppid() == pid)
    {
        if (pids[1] == 0)
        {
            for (int i = 0; i < 50000; i++)
            {
                for (int j = 0; j < 50000; j++)
                {
                    if (arr3[i] < arr3[j])
                    {
                        int temp = arr3[i];
                        arr3[i] = arr3[j];
                        arr3[j] = temp;
                    }
                }
            }
            ofstream myfile;
            myfile.open("arr3");
            for (int i = 0; i < 50000; i++)
            {
                myfile << arr3[i] << endl;
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
                    if (arr4[i] < arr4[j])
                    {
                        int temp = arr4[i];
                        arr4[i] = arr4[j];
                        arr4[j] = temp;
                    }
                }
            }
            ofstream myfile;
            myfile.open("arr4");
            for (int i = 0; i < 50000; i++)
            {
                myfile << arr4[i] << endl;
            }
            myfile.close();
            exit(0);
        }
    }
    else
    {
        waitpid(pids[1], &status, 0);
        waitpid(pids[2], &status, 0);
        ifstream myfile;
        myfile.open("arr3");
        for (int i = 0; i < 50000; i++)
        {
            myfile >> arr3[i];
        }
        myfile.close();
        myfile.open("arr4");
        for (int i = 0; i < 50000; i++)
        {
            myfile >> arr4[i];
        }
        myfile.close();
        int arr5[100000];
        int i = 0, j = 0, k = 0;
        while (i < 50000 && j < 50000)
        {
            if (arr3[i] < arr4[j])
            {
                arr5[k] = arr3[i];
                i++;
            }
            else
            {
                arr5[k] = arr4[j];
                j++;
            }
            k++;
        }

        auto t4 = steady_clock::now();
        /*for(int i=0;i<10000;i++){
            cout << arr5[i] << " ";
        }*/
        cout << "\nTempo di esecuzione: " << duration_cast<microseconds>(t4 - t3).count() << " microsecondi" << endl;
    }
}