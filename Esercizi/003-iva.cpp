#include <iostream>

using namespace std;

int main (int argc, char* argv[]){
    double prezzo, iva, prezzoFinale;
    cout<<"Inserisci prezzo del prodotto e iva: ";
    cin>>prezzo>>iva;
    prezzoFinale = prezzo + ((prezzo*iva)/100);
    cout.precision(2); // tutte le cifre del numero
    cout << fixed; //applica il precision solo alla parte decimale
    cout<<"Il prezzo finale è di "<<prezzoFinale<<endl;
    cout << defaultfloat;
    return 0;
}