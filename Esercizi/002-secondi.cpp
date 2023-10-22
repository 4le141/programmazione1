#include <iostream>

using namespace std;

int main (int argc, char* argv[]){
    int secondi, minuti, ore;
    cout<<"Inserisci i secondi da mezzanotte: ";
    cin>>secondi;
    ore = secondi/(60*60);
    secondi%=60*60;
    minuti = secondi/60;
    secondi%=60;
    cout<<"L'ora è: "<<ore<<":"<<minuti<<":"<<secondi<<endl;
    return 0;
}