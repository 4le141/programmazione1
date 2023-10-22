#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Studente{
  char nome[100];
  char cognome[100];
  int matricola;
  float media;
};

void stampa_studente(const Studente & s);

Studente genera_studente(char nome [], char cognome[], int matricola, float media);

bool riempi_database(Studente * database, char file[], int dim, int& indice);

int cerca_matricola(Studente * database, int matricola, int dim);

int cerca_nome_cognome(Studente * database, char nome[], char cognome[], int dim);

int studente_top_media(Studente * database, int dim);

void cercaMatricola(Studente * database, int dim), cercaNomeCognome(Studente * database, int dim), cercaMedia(Studente * database, int dim);

void addStudente(Studente* database, int dim, int& indice);

void stampaDatabase(Studente* database, int indice);

void salvaStudenti(Studente* database, int indice, char file[]);

int main(int argc, char *argv[]){
  if (argc!=4){
    cout<<"Usage: ./a.out <input> <dim> <output>"<<endl;
    exit(0);
  }
  int indice = 0;
  int dim=100;
  Studente * database = new Studente[dim];
  bool risultato = riempi_database(database, argv[1], atoi(argv[2]), indice);
  if (risultato==false){
    cout<<"Errore nella lettura da file";
  }else{
    int scelta;
    do{
      cout<<"0. Esci\n1. Cerca matricola\n2. Cerca nome e cognome\n3. Media più alta\n4. Aggiungi studente\n5. Stampa database"<<endl;
      cin>>scelta;
      switch (scelta){
      case 1:
	      cercaMatricola(database,dim);
	      break;
      case 2:
	      cercaNomeCognome(database,dim);
	      break;
      case 3:
	      cercaMedia(database,dim);
	      break;
      case 4:
	      addStudente(database,dim,indice);
	      break;
      case 5:
	      stampaDatabase(database,indice);
	      break;
      }
    }while(scelta!=0);
    salvaStudenti(database,indice,argv[3]);
    cout<<"Database salvato nel file "<<argv[3]<<endl;
  }
  return 0;
}

void salvaStudenti(Studente* database, int indice, char file[]){
  fstream output;
  output.open(file, ios::out);
  for (int i=0;i<indice;i++){
    output<<database[i].nome<<" "<<database[i].cognome<<" "<<database[i].matricola<<" "<<database[i].media;
    if (i=!indice-1){
      cout<<endl;
    }
  }
  output.close();
}

void addStudente(Studente* database, int dim, int& indice){
  if(indice>=dim){
    cout<<"Database pieno"<<endl;
    return;
  }
  char nome[100], cognome[100];
  int matricola;
  float media;
  cout<<"Inserisci in ordine nome, cognome, numero di matricola e media ponderata: ";
  cin>>nome>>cognome>>matricola>>media;
  database[indice]=genera_studente(nome,cognome,matricola,media);
	indice++;
}

void stampaDatabase(Studente* database, int indice){
  if(indice==0){
    cout<<"Database vuoto"<<endl;
  }
  for(int i=0; i<indice; i++){
    cout<<"Indice: "<<i<<endl;
    stampa_studente(database[i]);
    cout<<endl;
  }
}

void stampa_studente(const Studente & s){
  cout<<"Nome: "<<s.nome<<"\nCognome: "<<s.cognome<<"\nMatricola: "<<s.matricola<<"\nMedia: "<<s.media<<endl;
}

Studente genera_studente(char nome[], char cognome[], int matricola, float media){
  Studente s;
  strcpy(s.nome,nome);
  strcpy(s.cognome,cognome);
  s.matricola=matricola;
  s.media=media;
  return s;
}

bool riempi_database(Studente * database, char file[], int dim, int& indice){
  bool risultato=true;
  fstream input;
  input.open(file, ios::in);
    if (input.fail()){
      cout<<"Errore nell'aperture del file"<<endl;
      risultato=false;
    }else{
      indice=0;
      char nome[100], cognome[100];
      int matricola;
      float media;
      while (input>>nome>>cognome>>matricola>>media && indice<dim){
        database[indice]=genera_studente(nome,cognome,matricola,media);
	      indice++;
      }
    }
    input.close();
    return risultato;
}

int cerca_matricola(Studente * database, int matricola, int dim){
  int risultato=-1;
  for(int i=0;i<dim;i++){
    if(database[i].matricola==matricola){
      risultato = i;
    }
  }
  return risultato;
}

int cerca_nome_cognome(Studente * database, char nome[], char cognome[], int dim){
  int risultato=-1;
  for(int i=0;i<dim;i++){
    if(strcmp(database[i].nome,nome)==0 && strcmp(database[i].cognome,cognome)==0){
      risultato = i;
    }
  }
  return risultato;
}

int studente_top_media(Studente * database, int dim){
  int risultato=0;
  float media = database[0].media;
  for(int i=0;i<dim;i++){
    if(media<database[i].media){
      risultato = i;
      media = database[i].media;
    }
  }
  return risultato;
}

void cercaMatricola(Studente * database, int dim){
  int matricola;
    cout<<"Inserisci numero matricola da cercare: ";
    cin>>matricola;
    int res = cerca_matricola(database,matricola,dim);
      if(res>=0){
	cout<<"Indice: "<<res<<endl;
      }else{
	cout<<"Matricola inesistente"<<endl;
      }
}

void cercaNomeCognome(Studente * database, int dim){
  char nome[100], cognome[100];
    cout<<"Inserisci nome e cognome da cercare: ";
    cin>>nome>>cognome;
    int res = cerca_nome_cognome(database,nome,cognome,dim);
      if(res>=0){
	cout<<"Indice: "<<res<<endl;
      }else{
	cout<<"Matricola inesistente"<<endl;
      }
}

void cercaMedia(Studente * database, int dim){
  int res = studente_top_media(database,dim);
      if(res>=0){
	cout<<"Indice: "<<res<<endl;
      }else{
	cout<<"Matricola inesistente"<<endl;
      }
}
