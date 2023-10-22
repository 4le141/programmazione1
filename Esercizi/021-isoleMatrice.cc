#include <iostream>

using namespace std;

const int N = 6, M = 6;

void print(int matrix[][M], int n=N, int m=M);
void initRand(int matrix[][M], int n=N, int m=M);
int countIsole(int matrix[][M], int n=N, int m=M);
bool checkIsola(int matrix[][M], int riga, int colonna, int n=N, int m=M);

int main(){
  srand(time(NULL));
  int matrix[N][M];
  initRand(matrix);
  print(matrix);
  cout<<"\nCi sono "<<countIsole(matrix)<< " isole nella matrice"<<endl;
  return 0;
}

void print(int matrix[][M], int n, int m){
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void initRand(int matrix[][M], int n, int m){
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      matrix[i][j]=rand()%2;
    }
  }
}


int countIsole(int matrix[][M], int n, int m){
  int count=0;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if(matrix[i][j]==1){
        if(checkIsola(matrix,i,j)){
          count++;
        }
      }
    }
  }
  return count;
}

bool checkIsola(int matrix[][M], int riga, int colonna, int n, int m){
  int check=0;
  for (int i=riga-1; i<=riga+1;i++){
    for (int j=colonna-1; j<=colonna+1;j++){
      if(i>= 0 && i< n && j>=0 && j<m && !(i==riga && j==colonna)){
          check += matrix[i][j];
      }
    }
  }
  return !check;
}