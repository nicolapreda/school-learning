#include <iostream>
#include <string.h>


using namespace std;

char caratteriStringa(char prima[], char seconda[]){
    
    for (int i = 0; i < strlen(seconda); i++)
    {
        if (prima[i] == seconda[i])
        {
            cout<<prima[i]<<endl;
        }
        
    }
    

}

int main(){
    char prima[100], seconda[100];

    cout<<"inserire la prima stringa:\n";
    cin>>prima;
    cout<<"inserire la seconda stringa:\n";
    cin>>seconda;

    cout<<caratteriStringa(prima,seconda);

}