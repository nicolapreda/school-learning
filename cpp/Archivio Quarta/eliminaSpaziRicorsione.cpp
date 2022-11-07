#include <iostream>
#include <string>

using namespace std;

string eliminaSpazi(string s);


int main(){
    cout<<"inserisci una stringa: ";
     string s;
    getline(cin, s);

    cout<<"stringa senza spazi: "<<eliminaSpazi(s)<<endl;
    
    return 0;
}

string eliminaSpazi(string s){
    if(s.length() == 0)
        return "";
    else{
        if(s[0] == ' ')
            return eliminaSpazi(s.substr(1));
        else
            return s[0] + eliminaSpazi(s.substr(1));
    }
}