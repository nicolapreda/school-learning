#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int contaSpazi(char s[])
{
	int c = 0;
	
	for (int i = 0; i <= strlen(s); i++)
	{
		if ((s[i] == ' ') || (s[i] == ','))
			c++;
	}
	return c;
	
}

int main()
{
	char messaggio[100];

	cout << "Inserire messaggio: ";
	cin.getline(messaggio, 100);
	int c = contaSpazi(messaggio);
	
	cout << "Numero di spazi: " << c << endl;
}
