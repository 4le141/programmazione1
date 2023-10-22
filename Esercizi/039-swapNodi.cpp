#include <iostream>
#include <fstream>

using namespace std;
 
struct nodo
{
    int value;
    nodo *next;
};
typedef nodo *lista;
 
lista creaLista(char *);
void stampaLista(lista);
void inverti(lista &, int, int);
void distruggiLista(lista);
int dimensioneLista(lista);
void swap (lista precNodo1, lista precNodo2);
void aggiungiNodoInCoda(nodo* &primo, int val);
void stampaNodo(lista nodo);
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out <file.txt>" << endl;
        exit(0);
    }
 
    fstream input;
    input.open(argv[1], ios::in);
 
    lista lis = creaLista(argv[1]);
    stampaLista(lis);
 
    int pos1, pos2;
    int dim = dimensioneLista(lis);
 
    cout << "Dimensione: " << dim << endl;
 
    do
    {
        cout << "Posizioni: ";
        cin >> pos1 >> pos2;
    } while (pos1 < 0 || pos2 < 0 || pos1 >= dim || pos2 >= dim);
 
    inverti(lis, pos1, pos2);
    
    stampaLista(lis);
 
    distruggiLista(lis);
 
    return 0;
}
 
lista creaLista(char *file)
{
    fstream input;
    lista lis = NULL;
    input.open(file, ios::in);
 
    if (input.fail())
    {
        cout << "Errore nella lettura del file." << endl;
    }
    else
    {
 
        int n;
 
        while (input >> n)
        {
            aggiungiNodoInCoda(lis, n);
        }
    }
 
    input.close();
 
    return lis;
}
 
void inverti(lista &lis, int pos1, int pos2)
{
    
    nodo *nodo1prec = lis;
    nodo *nodo2prec = lis;
    for (int i = 0; i < pos1-1; i++){
        nodo1prec = nodo1prec->next;
    }
    for (int i = 0; i < pos2-1; i++){
        nodo2prec = nodo2prec->next;
    }
    if(pos1==0){
        lista nodo1 = lis;
        lista nodo2 = nodo2prec->next;
        nodo2prec->next = nodo1;
        lista nodo1succ = nodo1->next;
        nodo1->next = nodo2->next;
        lis = nodo2;
        nodo2->next=nodo1succ;
    }else{
        swap(nodo1prec,nodo2prec);
    }
}

void stampaNodo(lista nodo){
    cout<<"Nodo corrente = "<<nodo->value<<" Nodo successivo = "<<nodo->next->value<<endl;
}
 
void stampaLista(lista lis)
{
    int i=0;
    while (lis != NULL && i<10)
    {
        cout <<i<<": "<< lis->value << endl;
        i++;
        lis = lis->next;
    }
    cout << endl;
}
 
int dimensioneLista(lista lis)
{
    int dim;
    for (dim = 0; lis != NULL; dim++)
    {
        lis = lis->next;
    }
    return dim;
}
 
void distruggiLista(lista lis)
{
    nodo *prossimoNodo;
    while (lis != NULL)
    {
        prossimoNodo = lis->next;
        delete lis;
        lis = prossimoNodo;
    }
}

void swap (lista precNodo1, lista precNodo2){
    lista nodo1 = precNodo1->next;
    lista nodo2 = precNodo2->next;
    precNodo1->next=nodo2;
    precNodo2->next=nodo1;
    lista tmp = nodo1->next;
    nodo1->next=nodo2->next;
    nodo2->next=tmp;
}

void aggiungiNodoInCoda(nodo* &primo, int val){
    nodo* newNodo = new nodo;
    newNodo->value=val;
    newNodo->next=NULL;
    //controllo se la lista è vuota
    if (primo!=NULL){
        nodo* last;
        //trovo l'ultimo nodo
        for (last=primo; last->next!=NULL; last = last->next);
        last->next=newNodo;
    }else{
        primo=newNodo;
    }
}