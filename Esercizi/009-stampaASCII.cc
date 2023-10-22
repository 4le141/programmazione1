using namespace std;

#include <iostream>

int main(){
  char aMin='a';
  char zMin='z';
  for (int i=aMin;i<=zMin;i++){
    cout<<(char)i<<": "<<i<<endl;
  }
  cout<<"\n";
  char aMai='A';
  char zMai='Z';
  for (int i=aMai;i<=zMai;i++){
    cout<<(char)i<<": "<<i<<endl;
  }
  cout<<"\n\n";
  return 0;
}
