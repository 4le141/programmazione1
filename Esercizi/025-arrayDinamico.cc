#include <iostream>
#include <cstdlib>

using namespace std;

int * generate_numbers(int n);

int main(){
  srand(time(NULL));
  int n=0;
  cout<<"Inserisci lunghezza n dell'array: ";
  cin>>n;
  int * array=generate_numbers(n);
  for(int i=0;i<n;i++){
    cout<<i<<": "<<array[i]<<endl;
  }
  delete[] array;
  return 0;
}

int * generate_numbers(int n){
  int * array = new int[n];
  for(int i=0;i<n;i++){
    array[i]=rand()%100;
  }
  return array;
}
