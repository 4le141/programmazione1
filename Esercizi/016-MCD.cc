using namespace std;

#include <iostream>

int mcd(int int1, int int2);
int rec_findMCD(int int1,int int2, int n);

int main(){
  int int1, int2;
  cout<<"Inserisci i due numeri ";
  cin>>int1>>int2;
  cout<<"Il massimo comune divisore tra "<<int1<<" e "<<int2<<" è "<<mcd(int1,int2)<<endl;
  return 0;
}

int mcd(int int1, int int2){
  int mcd;
  if (int1>int2){
    int1 = int1%int2;
    mcd = rec_findMCD(int1,int2,int2);
  }else{
    int2 = int2%int1;
    mcd = rec_findMCD(int1,int2,int1);
  }
  return mcd;
}

int rec_findMCD(int int1,int int2, int n){
  if (int1%n == 0 && int2%n==0){
    return n;
  }else{
    return rec_findMCD(int1,int2,n-1);
  }
}
