#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

bool tryStringToInt(char stringa[], int &convertito);
void selectionSort(int stringa[],int l);

int main(int argc, char *argv[])
{
  int vettore[argc]; 
  /* $# -> argc
    $1 -> argv[1] */
  for (int i = 1; i < argc; i++)
  {
    int n;
    if (tryStringToInt(argv[i], n))
    {
      vettore[i-1] = atoi(argv[i]);
    }
  }
  selectionSort(vettore, argc);
}

bool tryStringToInt(char stringa[], int &convertito)
{
  convertito = atoi(stringa);
  return (convertito == 0 && stringa[0] == '0' && strlen(stringa) == 1 || convertito != 0);
}

void selectionSort(int vettore[], int l)
{

  int temp;
  for (int i = 0, min; i < 6; i++)
  {
    min = i;
    for (int j = i + 1; j < 6; j++)
      if (vettore[j] < vettore[min])
        min = j;

    temp = vettore[min];
    vettore[min] = vettore[i];
    vettore[i] = temp;
  }

  for (int x = 0; x < 6; x++)
  {
    cout << vettore[x] << endl;
  }
}
