#include <iostream>

using namespace std;

int fatt(int n);
void stampaPascal(int riga);
void stampaPascalRec(int riga, int i=0);
void stampaPascalRec2( int i, int j=0);
int binomiale(int i, int j);
void printSpaces(int n, int i=0);
int isEven (int n);
int isOdd (int n);
void crash(long long int i=0);

int main (int argc, char* argv[]){
    /*stampaPascal(4);
    cout<<endl;
    stampaPascalRec(4);
    cout<<"Inserisci riga e colonna: ";
    int riga, colonna;
    cin >> riga >> colonna;
    cout << binomiale(riga,colonna)<<endl;
    */
    crash();
    return 0;
}

int fatt(int n){
    if(n==0){
        return 1;
    }else{
        return n * fatt(n-1);
    }
}

void stampaPascal(int riga){
    for(int i=0; i<=riga; i++){
        printSpaces(riga-i);
        for(int j=0; j<=i; j++){
            cout << binomiale(i,j) << " ";
        }
        cout<<endl;
    }
}

void stampaPascalRec(int riga, int i){
    if (i>riga){
        return;
    }else{
        printSpaces(riga-i);
        stampaPascalRec2(i);
        cout<<endl;
        stampaPascalRec(riga,i+1);
    }
}

void stampaPascalRec2(int i, int j){
    if(j>i){
        return;
    }else{
        cout << binomiale(i,j) << " ";
        stampaPascalRec2(i,j+1);
    }
}

int binomiale(int sopra, int sotto){
    return fatt(sopra)/(fatt(sotto)*fatt(sopra-sotto));
}

void printSpaces(int n, int i){
    if(i>=n){
        return;
    }else{
        cout << " ";
        printSpaces(n,i+1);
    }
}

int sommaCifre(int n){
    if(n==0){
        return 0;
    }
    int cifra = n%10;
    return sommaCifre(n/10) + cifra;
}


int isEven (int n){
  if(n==0){
    return 1;
  }
  return isOdd(n-1);
}

int isOdd (int n){
  if(n==0){
    return 0;
  }
  return isEven(n-1);
}

void crash(long long int i){
    cout << i << endl;
    crash(i+1);
}