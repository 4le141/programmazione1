#include <iostream>
#include <cstdlib>

using namespace std;

int ** generate_matrix(int R, int C);

int main(){
  srand(time(NULL));
  int r=0,c=0;
  cout<<"Inserisci R righe e C colonne della matrice: ";
  cin>>r>>c;
  int ** matrix=generate_matrix(r,c);
  for(int i=0;i<r;i++){
    cout<<"\n"<<i<<" riga: ";
    for(int j=0;j<c;j++){
      cout<<j<<": "<<matrix[i][j]<<" ";
    }
  }
  cout<<endl;
  for(int i=0;i<r;i++){
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}

int ** generate_matrix(int R, int C){
  int ** matrix = new int*[R];
  for(int i=0;i<R;i++){
    matrix[i]=new int[C];
    for(int j=0;j<C;j++){
      matrix[i][j]=rand()%100;
    }
  }
  return matrix;
}
