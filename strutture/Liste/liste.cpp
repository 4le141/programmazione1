#include <iostream>

using namespace std;

struct nodo{
    int value;
    nodo* next;
};

void stampaNodo(nodo* nodo){
    if (nodo!=NULL)
    cout<<"Nodo stampato: " <<nodo->value<<endl;
    else
    cout<<"Nodo non esistente"<<endl;
}

void aggiungiNodo(nodo* &primo, int val){
    nodo* newNodo = new nodo;
    newNodo->value=val;
    if(primo!=NULL){
        newNodo->next=primo->next;
        primo->next=newNodo;
    }else{
        newNodo->next=NULL;
        primo=newNodo;
    }
    
}

void aggiungiNodoInTesta(nodo* &primo, int val){
    nodo* newNodo = new nodo;
    newNodo->value=val;
    newNodo->next=primo;
    primo=newNodo;
}

nodo* rimuoviNodoInTesta(nodo* &primo){
    if (primo!=NULL){
        nodo* nodo = primo;
        primo = primo->next;
        nodo->next=NULL;
        return nodo;
    }else{
        return NULL;
    }
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

void aggiungiNodoOrdinato(nodo* &primo, int val){
    //nel caso in cui la lista sia vuota oppure il nodo vada al primo posto
    if(primo==NULL || primo->value>val){
        aggiungiNodoInTesta(primo,val);
    }else{
        nodo* newNodo = new nodo;
        newNodo->value=val;
        nodo* last;
        //trovo elemento dopo il quale inserire quello nuovo in maniera ordinata
        for (last = primo; (last->next != NULL) && (last->next->value<val); last = last->next);
        newNodo->next=last->next;
        last->next=newNodo;
    }
}

int getLenght(nodo* primo){
    int l=0;
    for (nodo* nodo = primo; nodo!=NULL;nodo=nodo->next){
        l++;
    }
    return l;
}

void stampaLista(nodo* primo){
    int i;
    nodo* nodo;
    for(nodo=primo, i=0;nodo!=NULL;nodo=nodo->next, i++){
        cout<< "Elemento "<<i<<": "<< nodo->value<<endl;
    }
}

void stampaListaInvertita(nodo* primo){
  if(primo->next != NULL){
    stampaListaInvertita(primo->next);
  }
  cout<<primo->value<<" ";
}

nodo* rimuoviNodo(nodo* prec){
    nodo* nodo = prec->next;
    prec->next = prec->next->next;
    nodo->next=NULL;
    return nodo;
}

nodo* rimuoviNodoCercato(nodo* &primo, int val){
    nodo* ret=NULL;
    if(primo!=NULL){
        if(primo->value==val){
            ret=rimuoviNodoInTesta(primo);
        }else{
            nodo* primaDiCercato;
            for (primaDiCercato=primo;primaDiCercato!=NULL && primaDiCercato->next!=NULL && primaDiCercato->next->value!=val;primaDiCercato=primaDiCercato->next);
                if(primaDiCercato->next!=NULL){
                    nodo* cercato = primaDiCercato->next;
                    primaDiCercato->next=primaDiCercato->next->next;
                    cercato->next=NULL;
                    ret=cercato;
                }
        }
    }
    return ret;
}

nodo* rovesciamentoLista(nodo* primo){
    //nodo con cui scorrero la lista
    nodo* attuale=primo;
    //nodo con il quale terrò traccia dei nodi precedenti
    nodo* last = NULL;
    //scorro finchè non arrivo alla fine
    while ( attuale != NULL ) {
        nodo* temp;
        //cosi tengo traccia del nodo successivo
        temp = attuale->next;
        //inverto il next
        attuale->next = last;
        //mi tengo traccia del nodo precedente per il prossimo ciclo
        last = attuale;
        //passo al prossimo nodo
        attuale = temp;
    }
    //ritorno l'ultimo nodo della lista
   return last;
}

nodo * rovesciamentoCopia(nodo * primo) {
  nodo * last = NULL;
  for(nodo* attuale = primo; attuale!=NULL; attuale=attuale->next){
    nodo * newNodo = new nodo;
    newNodo->value = attuale->value;
    newNodo->next = last;
    last = newNodo;
  }
  return last;
}

// Dealloca la memoria della lista
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

// Ricerca a e ritorna l'elemento n-esimo se esite
nodo * get_n(nodo * s, int n) {
  // Se richiedo di prendere elemento con indice negativo ritorno NULL
  if (n < 0) return NULL;
  int i;
  for(i = 0;
      ((i < n) && (s != NULL));
       i++) {
    s = s->next;
  }
  // A questo punto se i == n, allora s punta la punto
  // giusto. Altrimenti s punta a NULL e lo possiamo ritornare.
  return s;
}

// Ritornare il nodo che precede un nodo x
nodo * prec(nodo * s, nodo * x) {
  // primo ed unico elemento uguale a x
  if (s == x) return x;
  // primo e unico elemento e' differente da x
  if ((s == NULL) && (s->next == NULL)) return NULL;

  nodo * t = s; // nodo precedente al nodo corrente che sto cercando,
		// inizializzato al primo elemento della lista
  nodo * l = s->next; // nodo che uso per scorrere la lista,
		      // inizializzato al secondo elemento della
		      // lista.

  while((l != NULL) && (l != x)) {
    // Modifico l e t per rispettare il loro significato, ovvero che t
    // punta l nodo che precede l
    t = l;
    l = l->next;
  }
  // raggiunto ultimo elemento e non c'e' nulla
  if (l == NULL) return NULL;
  return t;
}

nodo  * concat_se_ricorsiva(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return s2;
  s1->next = concat_se_ricorsiva(s1->next, s2);
  return s1;
}

nodo  * concat_se_iterativa(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return s2;
  if (s2 == NULL) return s1;

  nodo  * p = s1;

  while((p != NULL) && (p->next != NULL))
    p = p->next;

  p->next = s2;

  return s1;
}

nodo  * copy_seq(nodo  * s) {
  if (s == NULL) return NULL;
  nodo * t = new nodo;
  t->value = s->value;
  t->next = copy_seq(s->next);
  return t;
}

nodo  * concat_nose(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return copy_seq(s2);
  if (s2 == NULL) return copy_seq(s1);

  nodo  *cs1 = copy_seq(s1);
  nodo  *cs2 = copy_seq(s2);

  nodo  * p;

  for(p = cs1; ((p != NULL) && (p->next != NULL)); p = p->next);

  p->next = cs2;

  return cs1;
}

nodo  * concat_nose_recur(nodo  *s1, nodo  *s2) {
  if (s1 == NULL) return copy_seq(s2);

  nodo * t = new nodo;
  t->value = s1->value;
  t->next = concat_nose_recur(s1->next, s2);
  return t;
}

nodo *merge(nodo *firstNode,nodo *secondNode) {
    nodo *merged = new nodo;
    nodo *temp = new nodo;
    
    //merged is equal to temp so in the end we have the top Node.
    merged = temp;
 
    //while either firstNode or secondNode becomes NULL
    while(firstNode != NULL && secondNode != NULL) {
     
        if(firstNode->value<=secondNode->value) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
         
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }
    
   //any remaining Node in firstNode or secondNode gets inserted in the temp List
    while(firstNode!=NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }
 
    while(secondNode!=NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }
    //return the head of the sorted list
    return merged->next;
}
 
//function to calculate the middle Element
nodo *middle(nodo *head) {
    nodo *slow = head;
    nodo *fast = head->next;
    
    while(slow->next != NULL && (fast!=NULL && fast->next!=NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
 
//function to sort the given list
nodo *sort(nodo *head){
     
    if(head->next == NULL) {
        return head;
    }
 
    nodo *mid = new nodo;
    nodo *head2 = new nodo;
    mid = middle(head);
    head2 = mid->next;  
    mid->next = NULL;
    //recursive call to sort() hence diving our problem, and then merging the solution
    nodo *finalhead = merge(sort(head),sort(head2)); 
    return finalhead;
}

int main(){
    nodo* primo = NULL;
    aggiungiNodoOrdinato(primo,4);
    aggiungiNodoOrdinato(primo,2);
    aggiungiNodoOrdinato(primo,3);
    aggiungiNodoOrdinato(primo,1);
    aggiungiNodoOrdinato(primo,2);
    aggiungiNodoOrdinato(primo,0);
    nodo* ultimo = rovesciamentoCopia(primo);
    stampaLista(ultimo);
    cout<<"lista ordinata: "<<endl;
    stampaLista(sort(ultimo));
    return 0;
}