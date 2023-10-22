#include <iostream>

using namespace std;

void stampaArray(char v [], int dim);
void ruotaArrayInefficiente(char v [], int dim, int rotazione);
void ruotaArrayEfficiente(char v [], int dim, int rotazione);
void ruotaArrayEfficienteSemplice(char v [], int dim, int rotazione);
void ruotaArrayRecursive(char v [], int dim, int rotazione, int rotazioneCorrente);
void rotazioneSingola(char v [], int dim, int contatore = 0);


int main() {

    int j;
    char v [] = {'A','B','C','D','E'};
    const int dim = 5;

    cout << "Inserisci j: ";
    cin >> j;

    j = j % dim;

    stampaArray(v, dim);
    ruotaArrayInefficiente(v, dim, j);
    //ruotaArrayEfficienteConArray(v, dim, j);
    //ruotaArrayEfficiente(v, dim, j);
    stampaArray(v, dim);

    return 0;
}


void stampaArray(char v [], int dim) {
    for (int i = 0 ; i < dim ; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


void ruotaArrayEfficiente(char v [], int dim, int rotazione) {
    int rotazioniEffettuate = 0;
    for (int k = 0 ; k < rotazione && rotazioniEffettuate < dim; k++) {
        int temp = v[k];
        int indicePostoVuoto = k;
        int indiceElementoDaMuovere = rotazione + k;
        for (int i = 0 ; i < dim-1 && indiceElementoDaMuovere != k ; i++) {
            v[indicePostoVuoto] = v[indiceElementoDaMuovere];
            rotazioniEffettuate++;
            indicePostoVuoto = indiceElementoDaMuovere;
            indiceElementoDaMuovere = (indiceElementoDaMuovere + rotazione) % dim;
        }
        v[indicePostoVuoto] = temp;
        rotazioniEffettuate++;
    }
}


void ruotaArrayEfficienteConArray(char v [], int dim, int rotazione) {
    int * temp = new int[rotazione];
    for (int i = 0 ; i < rotazione ; i++) {
        temp[i] = v[i];
    }
    for (int i = 0 ; i < dim-rotazione ; i++) {
        v[i] = v[rotazione+i];
    }
    for (int i = 0 ; i < rotazione ; i++) {
        v[dim-rotazione+i] = temp[i];
    }
    delete [] temp;
}


void ruotaArrayInefficiente(char v [], int dim, int rotazione) {
    int temp;
    for (int i = 0 ; i < rotazione ; i++) {
        temp = v[0];
        for (int k = 0 ; k < dim-1 ; k++) {
            v[k] = v[k+1];
        }
        v[dim-1] = temp;
    }
}

void ruotaArrayRecursive(char v [], int dim, int rotazione, int rotazioneCorrente) {
    if (rotazioneCorrente < rotazione) {
        int temp = v[0];
        rotazioneSingola(v, dim);
        v[dim-1] = temp;
        rotazioneCorrente++;
        ruotaArrayRecursive(v, dim, rotazione, rotazioneCorrente);
    }
}
void rotazioneSingola(char v [], int dim, int contatore) {
    if (contatore < dim-1) {
        v[contatore] = v[contatore+1];
        contatore++;
        rotazioneSingola(v, dim, contatore);
    }
}