#include <iostream>

using namespace std;

int invertiNumero(int numero);
int isEven (int n);
int isOdd (int n)

int main(){
  int numero;
  cout << "Inserisci un numero: ";
  cin >> numero;
  cout << invertiNumero(numero) << endl;
}

int invertiNumero(int numero){
  int risultato = 0;
  while(numero != 0){
    int cifra = numero%10;
    numero/=10;
    risultato *= 10;
    risultato += cifra;
  }
  return risultato;
}
