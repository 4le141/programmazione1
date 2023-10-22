#include <iostream>

using namespace std;

void printSpaces(int n);
void printAst(int n);

int main (int argc, char* argv[]){
    int n;
    cout << "Inserisci l'altezza del triangolo: ";
    cin >> n;
    for (int i=1; i<=n; i++){
        printSpaces(n-i);
        printAst(i);
        cout<<endl;
    }
    return 0;
}

void printSpaces(int n){
    for (int i=0; i<n; i++){
        cout << " ";
    }
}

void printAst(int n){
    n = n*2-1;
    for (int i=1; i<=n; i++){
        cout << "*";
    }
}