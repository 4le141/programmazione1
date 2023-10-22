#include <iostream>
using namespace std;

int main ()
{
  cout << "\\n significa: " << "[\n]" << endl; //nuova riga
  cout << "\\t significa: " << "[\t]" << endl; //tabulazione orizzontale
  cout << "\\v significa: " << "[\v]" << endl; //tabulazione verticale
  cout << "\\b significa: " << "[\b]" << endl; //spazio indietro
  cout << "\\r significa: " << "[\r]" << endl; //ritorno carrello
  cout << "\\f significa: " << "[\f]" << endl; //avanzamento modulo (simile a tabulazione verticale)
  cout << "\\a significa: " << "[\a]" << endl; //segnale acustico
  cout << "\\\\ significa: " << "[\\]" << endl; //barra invertita
  cout << "\\\' significa: " << "[\']" << endl; //apice
  cout << "\\\" significa: " << "[\"]" << endl; //virgolette

  return 0;
}
