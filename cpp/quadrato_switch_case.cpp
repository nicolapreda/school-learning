#include <iostream>

using namespace std;

int main()
{
    int l, n;
    cout << "Inserisci il lato del quadrato:\n";
    cin >> l;
    do
    {
        cout << "Inserisci un numero compreso tra 1 e 5:\n";
        cin >> n;
    } while (n < 1 || n > 5);

    switch (n)
    {
    case 1:
        //Quadrato Pieno
        for (int righe = 0; righe < l; righe++)
        {
            for (int colonne = 0; colonne < l; colonne++)
            {
                cout << "* ";
            }
            cout << endl;
        }
        break;
    case 2:
        //Quadrato vuoto
        for (int c_righe = 1; c_righe <= l; c_righe++)
        {
            for (int c_colonne = 1; c_colonne <= l; c_colonne++)
            {

                if (c_righe != 1 && c_righe != l)
                {
                    if (c_colonne == 1 || c_colonne == l)
                    {
                        cout << "* ";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
                else
                {
                    cout << "* ";
                }
            }
            cout << endl;
        }
        break;
    case 3:
        //Quadrato vuoto + prima diagonale
        for (int c_righe = 1; c_righe <= l; c_righe++)
        {
            for (int c_colonne = 1; c_colonne <= l; c_colonne++)
            {

                if (c_righe != 1 && c_righe != l)
                {
                    if (c_colonne == 1 || c_colonne == l)
                    {
                        cout << "* ";
                    }
                    else
                    {
                        if (c_colonne == c_righe)
                        {
                            cout << "* ";
                        }
                        if (c_colonne != c_righe)
                        {
                            cout << "  ";
                        }
                    }
                }
                else
                {
                    cout << "* ";
                }
            }

            cout << endl;
        }
        break;
    case 4:
        //Quadrato vuoto + seconda diagonale
        for (int c_righe = 1; c_righe <= l; c_righe++)
        {
            for (int c_colonne = 1; c_colonne <= l; c_colonne++)
            {

                if (c_righe != 1 && c_righe != l)
                {
                    if (c_colonne == 1 || c_colonne == l)
                    {
                        cout << "* ";
                    }
                    else
                    {
                        if (c_colonne - 1 == l - c_righe)
                        {
                            cout << "* ";
                        }
                        else
                        {
                            cout << "  ";
                        }
                    }
                }
                else
                {
                    cout << "* ";
                }
            }

            cout << endl;
        }
        break;
    case 5:
        //Quadrato vuoto con prima e seconda diagonale
        for (int c_righe = 1; c_righe <= l; c_righe++)
        {
            for (int c_colonne = 1; c_colonne <= l; c_colonne++)
            {

                if (c_righe != 1 && c_righe != l)
                {
                    if (c_colonne == 1 || c_colonne == l)
                    {
                        cout << "* ";
                    }
                    else
                    {
                        //Prima Diagonale
                        if (c_colonne == c_righe)
                        {
                            cout << "*";
                        }
                        else if (c_colonne - 1 == l - c_righe)
                        {
                            cout << " * ";
                        }
                        
                        else{
                            cout<<"  ";
                        }
                   
                    }
                }
                else
                {
                    cout << "* ";
                }
            }

            cout << endl;
        }
        break;
    }
}