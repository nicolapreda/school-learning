#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fs;
    fs.open("inferno.txt", ios::in);

    string line;
    while (getline(fs, line))
    {
        cout << line << endl;
        std::string delimiter = " ";
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            std::cout << token << std::endl;
            line.erase(0, pos + delimiter.length());
        }
        std::cout << line << std::endl;
    }

    string word;
    string wordToCount;
    cout << "Inserisci la parola da contare: ";
    cin >> wordToCount;
    int count = 0;
    while (fs >> word)
    {
        if (word == wordToCount)
        {
            count++;
        }
    }
    cout << "La parola " << wordToCount << " compare " << count << " volte" << endl;
    //,.;'!?:
    fs.close();
    return 0;
}