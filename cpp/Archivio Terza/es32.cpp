#include <iostream>
#include <stdio.h>	/* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>	/* time */

using namespace std;

void caricaMatrice(int m[][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			srand(time(0));

			m[i][j] = rand() % 20;
		}
	}
}
void verificaContenuto(int m[][10], int n, int contenuto[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((m[i][j] >= 1) && (m[i][j] <= n * n))
			{
				contenuto[m[i][j]]++;
			}
		}
	}
}
void visualizzaMatrice(int m[][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << m[i][j] << "	";
		}
		cout << endl;
	}
}
void somma_RigheColonne(int m[][10], int n, int r[], int c[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			r[i] += m[i][j];
			c[j] += m[i][j];
		}
	}
}
void somma_Diagonali(int m[][10], int n, int v[])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				v[0] += m[i][j];
			if (i + j == n - 1)
				v[1] += m[i][j];
		}
}
bool verificaMagico(int n, int x[], int y[], int z[], int w[])
{
	for (int i = 1; i < n; i++)
		if (w[i] != 1)
			return false;
	for (int i = 1; i < n; i++)
		if (x[0] != x[i])
			return false;
	for (int i = 0; i < n; i++)
		if (x[0] != y[i])
			return false;
	for (int i = 0; i < 2; i++)
		if (x[0] != z[i])
			return false;
	return true;
}
int main()
{
	int m[10][10];
	int n = 7;
	int sommaRighe[10] = {0};
	int sommaColonne[10] = {0};
	int sommaDiagonali[2] = {0};
	int contenuto[100] = {0};

	caricaMatrice(m, n);

	visualizzaMatrice(m, n);
	verificaContenuto(m, n, contenuto);
	somma_RigheColonne(m, n, sommaRighe, sommaColonne);
	somma_Diagonali(m, n, sommaDiagonali);

	if (verificaMagico(n, sommaRighe, sommaColonne, sommaDiagonali, contenuto))
	{
		cout << "e' un quadrato magico" << endl;
	}
	else
	{
		cout << "non e' un quadrato magico" << endl;
	}
	return 0;
}
