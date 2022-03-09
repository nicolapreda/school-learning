#include <iostream>
using namespace std;


int main()
{					
	char c;
	/* preleva il carattere dall'input */
	cout<<"digita un carattere: ";
	cin>>c;
	/* stampa il valore restituito da ogni funzione in ctype.h
	   passando come argomento c */
	cout<<"isdigit "<<c<<" "<<isdigit(c)<<endl;
	cout<<"isalpha "<<c<<" "<<isalpha(c)<<endl;
	cout<<"isalnum "<<c<<" "<<isalnum(c)<<endl;
	cout<<"islower "<<c<<" "<<islower(c)<<endl;
	cout<<"isupper "<<c<<" "<<isupper(c)<<endl;
	cout<<"tolower "<<c<<" "<<tolower(c)<<endl;
	cout<<"toupper "<<c<<" "<<toupper(c)<<endl;

system("pause");
}