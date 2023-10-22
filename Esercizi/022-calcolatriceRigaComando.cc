#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  if(argc==4){
    float a, b, risultato;
    char operatore;
    a = atof(argv[1]);
    b = atof(argv[3]);
    operatore = argv[2][0];
    switch (operatore){
      case '+':
        risultato=a+b;
        break;
      case '-':
        risultato=a-b;
        break;
      case 'x':
        risultato=a*b;
        break;
      case '/':
        risultato=a/b;
        break;
      default:
        cout<<"L'operazione non è stata riconosciuta";
        break;
      }
  cout<<"Il risultato di "<<a<<" "<<operatore<<" "<<b<<" = "<<risultato<<"\n";
  }else{
    cout<<"Usage: a.out <a> <op> <b>"<<endl;
  }
  return 0;
}
