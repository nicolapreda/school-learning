#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

struct IP
{
	short int ip[4];

	string dottedDecimal;
	string classe;
	short int bitRete;
	short int bitHost;
	string subnetMask;
	string notazioneCIDR;
	short int broadcast[4] = { 0 };
	short int DG[4] = { 0 };
	short int rete[4] = { 0 };
	int n_hosts;
	string ipBinario;
	string subBinario;
};

void visualizzaIP(short int ip[4]);
void calcola(short int ip[4], IP &nuovo);
void mostra(IP ip);

int main()
{
	short int nuovo[4];
	cout << "Insert ip : ";
	for (int i = 0; i < 4; i++)
		cin >> nuovo[i];

	IP ip;
	calcola(nuovo, ip);
	mostra(ip);

	return 0;
}

void visualizzaIP(short int ip[4])
{
	for (int i = 0; i < 4; i++)
	{
		cout << ip[i];
		if (i != 3)
			cout << ".";
	}
}
void calcola(short int ip[4], IP &nuovo)
{
	for (int i = 0; i < 4; i++)
	{
		nuovo.ip[i] = ip[i];
		nuovo.dottedDecimal += to_string(ip[i]);

		// conversione binario
		int binary = 0, remainder, product = 1;
		while (ip[i] != 0)
		{
			remainder = ip[i] % 2;
			binary = binary + (remainder * product);
			ip[i] = ip[i] / 2;
			product *= 10;
		}
		nuovo.ipBinario += to_string(binary);
	}

	while (nuovo.ipBinario.length() < 8)
		nuovo.ipBinario = "0" + nuovo.ipBinario;

	// imposta classe e subnet mask
	if (nuovo.ipBinario[0] == '0')
	{
		nuovo.classe = "A";
		nuovo.subnetMask = "255.0.0.0";
		nuovo.notazioneCIDR = "255.255.255.0/8";
		nuovo.subBinario = "11111111000000000000000000000000";
		nuovo.bitRete = 8;
		nuovo.bitHost = 24;
		for (int i = 0; i < 4; i++)
		{
			if (i > 0)
			{
				nuovo.rete[i] = 0;
				nuovo.broadcast[i] = 255;
				nuovo.DG[i] = 254;

			}
			else
			{
				nuovo.rete[i] = nuovo.ip[i];
				nuovo.broadcast[i] = nuovo.ip[i];
				nuovo.DG[i] = nuovo.ip[i];

			}
		}
	}
	else if (nuovo.ipBinario[0] == '1' && nuovo.ipBinario[1] == '0')
	{
		nuovo.classe = "B";
		nuovo.subnetMask = "255.255.0.0";
		nuovo.notazioneCIDR = "255.255.255.0/16";
		nuovo.subBinario = "11111111111111110000000000000000";
		nuovo.bitRete = 16;
		nuovo.bitHost = 16;
		for (int i = 0; i < 4; i++)
		{
			if (i > 1)
			{
				nuovo.rete[i] = 0;
				nuovo.broadcast[i] = 255;
				nuovo.DG[i] = 254;

			}

			else
			{
				nuovo.rete[i] = nuovo.ip[i];
				nuovo.broadcast[i] = nuovo.ip[i];
				nuovo.DG[i] = nuovo.ip[i];

			}
		}
	}
	else if (nuovo.ipBinario[0] == '1' && nuovo.ipBinario[1] == '1' && nuovo.ipBinario[2] == '0')
	{
		nuovo.classe = "C";
		nuovo.subnetMask = "255.255.255.0";
		nuovo.notazioneCIDR = "255.255.255.0/24";
		nuovo.subBinario = "11111111111111111111111100000000";
		nuovo.bitRete = 24;
		nuovo.bitHost = 8;
		for (int i = 0; i < 4; i++)
		{
			if (i > 2)
			{
				nuovo.rete[i] = 0;
				nuovo.broadcast[i] = 255;
				nuovo.DG[i] = 254;
			}
			else
			{
				nuovo.rete[i] = nuovo.ip[i];
				nuovo.broadcast[i] = nuovo.ip[i];
				nuovo.DG[i] = nuovo.ip[i];
			}
		}
	}

	else if (nuovo.ipBinario[0] == '1' && nuovo.ipBinario[1] == '1' && nuovo.ipBinario[2] == '1' && nuovo.ipBinario[3] == '0')
	{
		nuovo.classe = "D";
		nuovo.subnetMask = "Non definita";
		nuovo.subBinario = "Non definita";
		nuovo.bitRete = 0;
		nuovo.bitRete = 0;
	}
	else
	{
		nuovo.subnetMask = "Non definita";
		nuovo.subBinario = "Non definita";
		nuovo.classe = "E";
		nuovo.bitRete = 0;
		nuovo.bitRete = 0;
	}

	nuovo.n_hosts = pow(2, nuovo.bitHost);
}

void mostra(IP ip)
{
	cout << endl;
	cout << "IP : ";
	visualizzaIP(ip.ip);
	cout << endl;
	cout << "IP BINARIO: " << ip.ipBinario << endl;
	cout << "DOTTED DECIMAL: " << ip.dottedDecimal << endl;
	cout << "SUBNET MASK : " << ip.subnetMask << endl;
	cout << "SUBNET MASK BINARIO: " << ip.subBinario << endl;
	cout << "CLASSE : " << ip.classe << endl;
	cout << "BIT RETE : " << ip.bitRete << endl;
	cout << "BIT HOST : " << ip.bitHost << endl;
	cout << "NUMERO HOST : " << ip.n_hosts << endl;
	cout << "INDIRIZZO DI RETE: ";
	for(int i = 0; i < 4; i++){
		cout << ip.rete[i];
		if(i < 3)
			cout << ".";
	}
	cout << endl;
	cout << "INDIRIZZO DI BROADCAST: ";
	for(int i = 0; i < 4; i++){
		cout << ip.broadcast[i];
		if(i < 3)
			cout << ".";
	}
	cout << endl;
	cout << "DEFAULT GATEWAY: ";
	for(int i = 0; i < 4; i++){
		cout << ip.DG[i];
		if(i < 3)
			cout << ".";

	}
	cout<<endl;

}
