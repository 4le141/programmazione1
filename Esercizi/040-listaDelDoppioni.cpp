#include <iostream>

using namespace std;

struct nodo{
    int value;
    nodo* next;
};

nodo* rimuoviNodo(nodo* prec);
void aggiungiNodoInCoda(nodo* &primo, int val);
void stampaLista(nodo* primo);
void rimuoviDoppioni(nodo* primo);
void delete_list(nodo * & s);

int main (int argc, char* argv[]){
    nodo* lista = NULL;
    aggiungiNodoInCoda(lista,1);
    aggiungiNodoInCoda(lista,1);
    aggiungiNodoInCoda(lista,2);
    aggiungiNodoInCoda(lista,1);
    aggiungiNodoInCoda(lista,2);
    aggiungiNodoInCoda(lista,2);
    aggiungiNodoInCoda(lista,3);
    aggiungiNodoInCoda(lista,2);
    stampaLista(lista);
    rimuoviDoppioni(lista);
    stampaLista(lista);
    delete_list(lista);
    return 0;
}

nodo* rimuoviNodo(nodo* prec){
    nodo* nodo = prec->next;
    prec->next = prec->next->next;
    nodo->next=NULL;
    return nodo;
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

void stampaLista(nodo* primo){
    int i;
    nodo* nodo;
    for(nodo=primo, i=0;nodo!=NULL;nodo=nodo->next, i++){
        cout<< "Elemento "<<i<<": "<< nodo->value<<endl;
    }
    cout<<endl;
}

void rimuoviDoppioni(nodo* primo){
    while(primo!=NULL){
        int val = primo->value;
        nodo* corrente = primo;
        while (corrente->next!=NULL){
            if (corrente->next->value==val){
                nodo* nodoRimosso=rimuoviNodo(corrente);
                delete nodoRimosso;
            }else{
                corrente = corrente->next;
            }
        }
        primo = primo->next;
    }
}

void delete_list(nodo * & s) {
  // Alla fine la lista e' vuota. Passaggio per riferimento.
  while(s != NULL) {
    // Salvo il valore del nodo corrente
    nodo * t = s;
    // Avanzo al nodo sucessivo
    s = s->next;
    // Dealloco il nodo salvato
    delete t;
  }
}