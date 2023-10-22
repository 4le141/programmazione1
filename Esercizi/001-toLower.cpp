#include <iostream>

using namespace std;

int main (int argc, char* argv[]){
    char upper, lower;
    cout<<"Inserisci il carattere in maiuscolo: ";
    cin>>upper;
    if(upper >= 'A' && upper <= 'Z'){
        lower = upper-('A'-'a');
        cout<<"Il carattere minuscolo è: "<<lower<<endl;
    }else{
        cout<<"Il carattere inserito non è corretto"<<endl;
    }
    return 0;
}