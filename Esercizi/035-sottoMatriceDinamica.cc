#include <iostream>
#include <cstdlib>

using namespace std;

int ** generate_matrix(int R, int C){
  int ** matrix = new int*[R];
  for(int i=0;i<R;i++){
    matrix[i]=new int[C];
    for(int j=0;j<C;j++){
      matrix[i][j]=rand()%10;
    }
  }
  return matrix;
}

void viewMatrix(int **matrix, int row, int column){
  for(int i=0;i<row;i++){
    cout<<"\n"<<"";
    for(int j=0;j<column;j++){
      cout<<matrix[i][j]<<" ";
    }
  }
  cout<<endl;
}

void viewSottoMatrice(int **matrix, int firstRow, int firstColumn, int dimRow, int dimColumn){
  for(int i=firstRow;i<dimRow;i++){
    cout<<"\n"<<"";
    for(int j=firstColumn;j<dimColumn;j++){
      cout<<matrix[i][j]<<" ";
    }
  }
  cout<<endl;
}

void deleteMatrix(int** matrix, int r){
  for(int i=0;i<r;i++){
    delete[] matrix[i];
  }
  delete[] matrix;
}

int main(int argc, char *argv[]){
  int righe, colonne;
  cout<<"Inserisci la dimensione della matrice: ";
  cin>>righe>>colonne;
  int ** matrix=generate_matrix(righe,colonne);
  viewMatrix(matrix,righe,colonne);
  int firstRow, firstColumn, dimRow, dimColumn;
  cout<<"Inserisci coordinate del primo elemento (riga,colonna) e dimensioni sotto matrice (numero di righe, numero di colonne): ";
  cin>>firstRow>>firstColumn>>dimRow>>dimColumn;
  if(firstRow+dimRow>righe){
    dimRow=righe;
  }else{
    dimRow=firstRow+dimRow;
  }
  if(firstColumn+dimColumn>colonne){
    dimColumn=colonne;
  }else{
    dimColumn=firstColumn+dimColumn;
  }
  viewSottoMatrice(matrix, firstRow, firstColumn,dimRow,dimColumn);
  deleteMatrix(matrix, righe);
  return 0;
}
