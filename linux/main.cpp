#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
int PID = fork();
int PID2 = fork();
if(PID != 0 && PID2 != 0){
	cout<<"sono il padre"<<PID<<" - "<<PID2<<endl;
}

if(PID == 0 && PID2 == 0){
	cout<<"sono il figlio"<<PID<< " - "<<PID2<<"endl;
}

if(PID != 0 && PID2 == 0){
}
