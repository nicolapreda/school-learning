#include<iostream>
using namespace std;

int main()
{
	int m[100][100],cornici[50]={0};
	int k,i,j,nr,nc,maxrc,ncornici;
	cout<<"Numero righe matrice..: ";
	cin>>nr;
	cout<<"Numero colonne matrice: ";
	cin>>nc;	
	for(i = 0; i < nr; i++)
		for(j = 0; j < nc; j++){
			m[i][j] = 1;
		} 

	for(i = 0; i < nr; i++){
		for(j = 0; j < nc; j++)
			cout<<m[i][j]<<'\t';
        cout<<endl;
    }
	
	maxrc=(nr>nc)?nc:nr;
	ncornici=maxrc/2+maxrc%2;
	cout<<"Numero cornici: "<<ncornici<<endl;
	
	for(k=0;k<ncornici;k++){
		cornici[k]=0;
		for(i=0+k;i<nr-k;i++)
			for (j=0+k;j<nc-k;j++)
				cornici[k]+=m[i][j];
	}

	for(i=0;i<ncornici;i++)
      cout<<"Somma elementi cornice "<<i<<": "<<cornici[i]-cornici[i+1]<<endl;
	
	
	return 0;
}
