#include <iostream>

using namespace std;

double potenza(double base, double esponente);
double rec_potenza(double numero, double potenza=2);

int main(){
  double n,p;
  cout<<"Inserisci un base ed esponente della potenza ";
  cin>>n>>p;
  cout<<"La potenza di "<<n<<" alla "<<p<<" è "<<potenza(n,p)<<endl;
  return 0;
}

double potenza(double base, double esponente){
  double res;
  if (esponente<0){
    res = 1.0 / rec_potenza(base, esponente * -1);
  }else{
    res = rec_potenza(base,esponente);
  }
  return res;
}

double rec_potenza(double numero, double potenza){
  if (potenza==0){
    return 1;
  }
  return numero*rec_potenza(numero,potenza-1);
}
