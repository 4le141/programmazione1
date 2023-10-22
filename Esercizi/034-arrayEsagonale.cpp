#include <iostream>

using namespace std;

int* creaArray(int lenght);
void riempiArray(int* array, int lenght, int i=0);
int esagonale(int numero);
void stampaArray(int* array, int lenght, int i=0);

int main (int argc, char* argv[]){
    int N=0;
    cout<<"Inserisci un numero positivo N (lunghezza dell'array): ";
    cin>>N;
    int* array = creaArray(N);
    stampaArray(array, N);
    delete[] array;
    return 0;
}

int* creaArray(int lenght){
    int* array = new int[lenght];
    riempiArray(array,lenght);
    return array;
}

void riempiArray(int* array, int lenght, int i){
    if(i<lenght){
        array[i]=esagonale(i);
        riempiArray(array,lenght,i+1);
    }
}

int esagonale(int numero){
    return (numero*(2*numero-1));
}

void stampaArray(int* array, int lenght, int i){
    if(i<lenght){
        cout<<array[i]<<" ";
        stampaArray(array,lenght,i+1);
    }else{
        cout<<endl;
    }
}