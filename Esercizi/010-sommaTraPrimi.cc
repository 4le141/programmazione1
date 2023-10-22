using namespace std;

#include <iostream>
#include <cmath>

bool checkPrimo(int numero){
  int i=2;
  bool primo=true;
  while (i<=sqrt(numero) && primo==true){
    primo=!(numero%i==0);
    i++;
  }
  return primo;
}

int main(){
  int  n;
  cout<<"Inserisci l'intero: ";
  cin>>n;
  bool trovato=false;
  for (int i=1;i<=(n/2);i++){
    if(checkPrimo(i)){
      int j = n-i;
      if(checkPrimo(j)){
	cout<<i<<" + "<<j<<" = "<<n<<endl;
	trovato = true;
      }
    }
  }
  if(trovato==false){
    cout<<"Non c'è nessuna somma di numeri primi che vale "<<n<<endl;
  }
  return 0;
}
