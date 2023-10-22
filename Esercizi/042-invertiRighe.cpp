#include <iostream>
#include <fstream>

using namespace std;

struct messaggio{
    char testo[100];
};

struct nodo{
  messaggio* val;
  nodo* next;
};

typedef nodo* pila;

static bool emptyp (const pila & s) {
  return (s == NULL);
}

void init(pila & s) {
  s = NULL;
}

bool top (messaggio* &n,const pila & s) {
  bool res;
  if (emptyp(s))
    res=false;
  else {
    n=s -> val;
    res=true;
  }
  return res;
}

// memo: "new (nothrow) ..." restituisce NULL
// senza generare eccezioni se l'allocazione non va a buon fine
bool push (messaggio* n,pila & s) {
  bool res;
  nodo * np = new (nothrow) nodo;
  if (np==NULL)
    res = false;
  else {
    np -> val = n;
    np -> next = s;
    s = np;
    res = true;
  }
  return res;
}

bool pop (pila & s) {
  bool res;
  if (emptyp(s))
    res=false;
  else {
    nodo *first = s;
    s = s -> next;
    delete first->val;
    delete first; 	// liberare la memoria: cancella
    res=true;             // l'oggetto puntato da first
  }
  return res;
}

void print (const pila & s) 
{
  for (nodo *first = s; first!=NULL; first = first -> next){
    cout << first->val->testo << endl;
  }
}

void deinit(pila & s) {
  while (!emptyp(s))
    pop(s);
}

void stringCopy(const char stringaDa[],char stringaA[]){
  int i;
  for(i=0; stringaDa[i]!='\0';i++){
    stringaA[i]=stringaDa[i];
  }
  stringaA[i]='\0';
}

int main(int argc, char * argv []){
    if (argc != 3){
        cout << "Usage: ./a.out input.txt output.txt" << endl;
        exit(1);
    }
    fstream input, output;
    input.open(argv[1], ios::in);

    if (input.fail()){
        cout << "Il file in input non esiste!" << endl;
        input.close();
        exit(1);
    }
    output.open(argv[2], ios::out);
    char buffer[100];

    pila pila;
    init(pila);

    while(input.getline(buffer,100)){
        messaggio* mex = new messaggio;
        stringCopy(buffer,mex->testo);
        push(mex,pila);
    }
    while(!emptyp(pila)){
        messaggio* mex;
        top(mex,pila);
        cout << mex->testo << endl;
        output << mex->testo << endl;
        pop(pila);
    }
    input.close();
    output.close();
  
  return 0;
}