#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

const int N = 3, P = 2, M = 3;

int C[N][M];

void formula(int A[N][P], int B[P][M], int C[N][M]);

int main(int argc, char** argv) {
	
	int A[N][P] = {
		{3,5},
		{1,2},
		{4,2},
	
	};
	int B[P][M]={
		{4,1,2},
		{3,2,3},
		};
	
	formula(A, B, C);
	return 0;
}

void formula(int A[N][P], int B[P][M], int C[N][M]){
	
	int x=0 , y=0;
	for(int i = 0; i < N; i++){
		for(int k = 0; k < P; k++){
			
			if(k%2==0){
				for(int j = 0; j < M; j++){
					C[y][x] = A[i][k] * B[k][j];
					x++;
					
				}	
			}
			
			
			else{
				for(int j = 0; j < M; j++){
					C[y][x] += A[i][k] * B[k][j];
					x++;
				}
				y++;	
			}
			
			x = 0;
			
		}
		
		
		
	}
	
	
	for(int i=0; i<N; i++){
		for(int k=0; k<M; k++){
			cout<<C[i][k]<<'\t';
		}
		
		cout<<endl;
	}
	
}
