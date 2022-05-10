#include <iostream>
//include random lib
#include <cstdlib>
//include time lib
#include <ctime>

using namespace std;

// create a function that checks if matrix is sorted
bool isSorted(int matrix[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > matrix[i][j + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char** argv) {
    int matrix[3][3];
    //insert into matrix crescent values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i * 3 + j;
        }
    }
    //print matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
        
    // call issorted function
    cout<< isSorted(matrix, 3)<<endl;

    
    
    return 0;
}