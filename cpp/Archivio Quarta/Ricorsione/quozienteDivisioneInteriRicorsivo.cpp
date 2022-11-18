#include<iostream>
using namespace std;


int quoziente(int x, int y){
   if (x < y) return 0;
   return 1+quoziente(x-y,y);
}

int main() {
	int x,y;
	cout<<"Inserire dividendo: ";
	cin>>x;
	cout<<"Inserire divisore.: ";
	cin>>y;
	cout<<"Quoziente.........: "<<quoziente(x,y)<<endl;
}