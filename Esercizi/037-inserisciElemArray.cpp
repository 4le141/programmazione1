#include <iostream>

using namespace std;

void print(const int array[],int lenght);
void randomArray(int array[],int lenght);
void insert(int array[], int lenght, int val, int pos);

int main(){
  srand(time(NULL));
  const int n=10;
  int array1[n];
  randomArray(array1,n);
  print(array1,n);
  int val, pos;
  cout << "Inserisci elemento e posizione dell'elemento da inserire: ";
  cin >> val >> pos;
  insert(array1,n,val,pos);
  print(array1,n);
  return 0;
}

void print(const int array[],int lenght){
    cout << "Array: ";
    for (int i=0;i<lenght;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

void randomArray(int array[],int lenght){
  for (int i=0;i<lenght;i++){
    array[i]=rand()%10;
  }
}

void insert(int array[], int lenght, int val, int pos){
    for(int i=lenght-2 ; i>=pos ; i--){
        array[i+1]=array[i];
    }
    array[pos]=val;
}