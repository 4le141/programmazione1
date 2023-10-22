#include <iostream>
#include <cstdlib>

using namespace std;

const int max_dim=10;
const int max_pattern=2;

bool isEqual(int *testo, int *pattern){
  bool ret = true;
  for (int i=0;i<max_pattern && ret==true;i++){
    if (testo[i]!=pattern[i]){
      ret = false;
    }
  }
  return ret;
}

bool isInside(int *testo, int *pattern){
  bool ret=false;
  for (int i=0;i<=max_dim-max_pattern && ret==false;i++){
    if (testo[i]==pattern[0]){
      ret = isEqual(&testo[i],pattern);
    }
  }
  return ret;
}

void viewArray(int *array, int dim){
  for(int i=0;i<dim;i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}

int main(int argc, char *argv[]){
  srand(time(NULL));
  int testo[max_dim];
  int pattern[max_pattern];
  for(int i=0;i<max_dim;i++){
    testo[i] = rand() % 10;
  }
  for(int i=0;i<max_pattern;i++){
    pattern[i] = rand() % 10;
  }
  viewArray(testo,max_dim);
  viewArray(pattern,max_pattern);
  if(isInside(testo,pattern)==true){
    cout<<"L'array è contenuto";
  }else{
    cout<<"L'array non è contenuto";
  }
  cout<<endl;
  return 0;
}
