#include "030-cifrarioCesare-caesar.h"

void crypt(char parola[], int chiave) {
    for (int i = 0 ; parola[i] != '\0'; i++) {
        parola[i] += chiave;
        if (parola[i] > 'z') {
            parola[i] = parola[i] - 'z' + 'a' - 1;
        }
    }
}

void decrypt(char parola[], int chiave) {
    for (int i = 0 ; parola[i] != '\0'; i++) {
        parola[i] -= chiave;
        if (parola[i] < 'a') {
            parola[i] = parola[i] + 'z' - 'a' + 1;
        }
    }
}
