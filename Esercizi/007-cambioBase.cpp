#include <iostream>
#include <cmath>

using namespace std;

int toDecimal(const char numero[], int base);

int getLenght(const char parola[]);

int getNumber(const char c, int base);

long long int power(int base, int exp);

int toDecimal(int binario, int base);

int main (int argc, char* argv[]){
    char binario[11];
    int num;
    cin>>num;
    cout << toDecimal(num,2);
    int decimale;
    cout<<"Inserisci il numero in binario: ";
    cin>>binario;
    decimale = toDecimal(binario,2);
    if(decimale==-1){
        cout<<"Errore nell'input"<<endl;
    }else{
        cout<<"Il numero in decimale equivale a "<<decimale<<endl;
    }
    return 0;
}

int toDecimal(const char numero[], int base){
    int ret=0;
    int lenght = getLenght(numero);;
    bool correct=true;
    for(int i=lenght-1; i>=0 && correct==true; i--){
        int cifra = getNumber(numero[i],base);
        if (cifra==-1){
            correct=false;
        }else{
            ret+=cifra*power(base,lenght-1-i);
        }
    }
    if(correct==false){
        ret=-1;
    }
    return ret;
}

int toDecimal(int binario, int base){
    int res = 0;
    int esponente = 0;
    while(binario!=0){
        int cifra = binario % 10;
        res += cifra*power(base,esponente);
        esponente++;
        binario /= 10;
    }
    return res;
}

int getLenght(const char parola[]){
    int ret;
    for(ret = 0; parola[ret]!='\0';ret++);
    return ret;
}

long long int power(int base, int exp){
  if (exp == 0) return 1;
  return base * power(base, exp-1);
}

int getNumber(const char c, int base) {
    int ret;
    if (c >= '0' && c <= '9') {
        ret = int(c - '0');
    }
    else if (c >= 'a' && c <= 'z') {
        ret = 10 + int(c - 'a');
    }
    else if (c >= 'A' && c <= 'Z') {
        ret = 10 + int(c - 'A');
    }
    else {
        ret = -1;
    }
    if(ret!=-1 && ret>=base){
        ret=-1;
    }
    return ret;
}