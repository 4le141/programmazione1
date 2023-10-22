using namespace std;

#include <iostream>

int rec_binario(int numero);

int main(){
  int n;
  cout<<"Inserisci un numero ";
  cin>>n;
  cout<<"Il risultato è "<<rec_binario(n)<<endl;
  return 0;
}

int rec_binario(int numero){
  int valore;
  if (numero==0){
    valore = 0;
  }else{
    valore = (numero%2) + 10*rec_binario(numero/2);
  }
  return valore;
}

/*
int rec_fatt(int n){
   if (dividendo<divisore){
    return 0;
  }else{
    return 1 + rec_divisione(dividendo-divisore,divisore);
  }
}
 */
