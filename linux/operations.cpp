#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        int op1 = atoi(argv[1]);
        int op2 = atoi(argv[2]);
        int result;
        int PIDs[4] = {-1, -1, -1, -1};
        int padre = getpid();
        for (int i = 0; i < 4; i++)
        {
            if (getpid() == padre)
            {
                PIDs[i] = fork();
            }

            if (PIDs[i] == 0)
            {
                cout << "Sono il figlio " << i + 1 << endl;
            }
        }
        for (int f = 0; f < 4; f++)
        {
            cout << PIDs[f] << " . ";
        }
        cout << endl;

        if (PIDs[0] == 0)
        {
            result = op1 + op2;
            exit(result);
        }
        else if (PIDs[1] == 0)
        {
            result = op1 - op2;
            exit(result);
        }
        else if (PIDs[2] == 0)
        {
            result = op1 * op2;
            exit(result);
        }
        else if (PIDs[3] == 0)
        {
            result = op1 / op2;
            exit(result);
        }
        else
        {
            int valore;
            for (int i = 0; i < 4; i++)
            {

                waitpid(PIDs[i], &valore, 0);
                cout << "Figlio " << i + 1 << ": " << WEXITSTATUS(valore) << endl;
            }
        }
    }
    else
        cout << "parametri mancanti";
    return 0;
}
