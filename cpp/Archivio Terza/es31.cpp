#include <iostream>

using namespace std;

int main()
{
	int durata, tipo, priorit;
	double prezzo;
	do
	{
		cout << "Durata (settimanale => 1, mensile => 2, annuale => 3)\n";
		cin >> durata;
	} while (durata != 1 && durata != 2 && durata != 3);
	do
	{
		cout << "tipo (zona centrale => 1, zona periferica => 2, entrambe => 3)\n";
		cin >> tipo;
	} while (tipo != 1 && tipo != 2 && tipo != 3);
	do
	{
		cout << "Priorità nelle ore di punta? (Si => 1, No => 2)\n";
		cin >> priorit;
	}while(priorit != 1 && priorit != 2);

	switch (durata)
	{
	case 1:
		switch (tipo)
		{
		case 1:
			prezzo = 10;
			break;
		case 2:
			prezzo = 5;
			break;
		case 3:
			prezzo = 15;
			break;
		}
		break;
	case 2:
		switch (tipo)
		{
		case 1:
			prezzo = 30;
			break;
		case 2:
			prezzo = 20;
			break;
		case 3:
			prezzo = 40;
			break;
		}
		break;
	case 3:
		switch (tipo)
		{
		case 1:
			prezzo = 250;
			break;
		case 2:
			prezzo = 150;
			break;
		case 3:
			prezzo = 300;
			break;
		}
		break;
	}
	if (priorit == 1)
	{
		prezzo = prezzo * 0.8;
	}

	cout << "Prezzo totale: " << prezzo << "€\n\n";
	return main();
}
