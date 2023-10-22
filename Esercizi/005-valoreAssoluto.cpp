#include <iostream>

using namespace std;

int main (int argc, char* argv[]){
    int a,b,risultato;
    cout<<"Inserisci due numeri interi a e b: ";
    cin>>a>>b;
    risultato=(a-b)*((a>b)-(b>a));
    cout<<"|a-b| = "<<risultato<<endl;
    return 0;
}