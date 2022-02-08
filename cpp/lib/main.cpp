#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iterator>
#include <charconv>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

int main(){
    float n = 45.324234523534;
    int arrotondamento = pow(10, 10);
    float valore = (int)(n * arrotondamento + .5);
    cout<< (float)valore / arrotondamento;

}