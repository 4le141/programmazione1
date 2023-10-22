#include <iostream>

using namespace std;

int main() {
  int x=1;  // x variabile tipo int
  int *px;   // px variabile puntatore
  px=&x;   // accede alla variabile
                 // puntatore
  *px=x+1; /* accede alla cella di
 	             memoria puntata dalla
		     variabile puntatore */

  // quanto vale x?
  cout << "x = " << x << endl; //valore di x
  cout << "&x = " << &x << endl; //indirizzo di x
  cout << "px = " << px << endl; //valore di px
  cout << "&px = " << &px << endl; //indirizzo di px
  cout << "*px = " << *px << endl; //valore di x
  cout << "&*px = " << &*px << endl; //valore di px
  return 0;
}
