// In un file di testo "pezzi.txt" vengono memorizzati, giorno per giorno, la data e il numero dei pezzi prodotti da una macchina.
// Ogni riga contiene, separati da una virgola, la data del giorno nella forma ggmmaaaa e il numero dei pezzi prodotti .
// Scrivere un programma C++ che legga il file riga per riga e visualizzi: 1)
// l'elenco dei giorni con il numero di pezzi prodotti. la data deve essere stampata nella forma gg nomemese aaaaa 2)
// la media dei pezzi prodotti 3) il numero dei pezzi e il giorno (o i giorni) in cui la produzione è stata massima
 
#include <iostream>
#include <fstream>
#include <iomanip>
 
using namespace std;
 
const char slash = '/';
 
bool is_a_number(char str);
bool is_a_date(char *stringa);
bool estrai_data(char *str, int &giorno, int &mese, int &anno);
void leggi_mese(int n);
float media(int num, int howMany);
void stampa_array(int a[], int dim);
void find_the_day_max(int max, fstream &testo);
int vett(int *&v, fstream &input, int count = 0);
 
int main(int argc, char *argv[])
{
    fstream input, in;
 
    if (argc != 2)
    {
        cout << "Usage: a.out <input> " << endl;
        exit(0);
    }
 
    input.open(argv[1], ios::in);
    in.open(argv[1], ios::in);
 
    if (input.fail())
    {
        cout << "errore nell'apertura del file " << endl;
        exit(0);
    }
 
    char *data = new char[10];
    int number, totale = 0, count = 0, max = 0;
    int *numeri;
 
    count = vett(numeri, in);
 
    /*while (!input.eof())
    {
        input >> data;
        if (is_a_date(data))
        {
            input >> number;
            if (max < number)
            {
                max = number;
            }
            cout << "pezzi: " << number;
            // numeri[count] = number;
            count++;
            totale += number;
            cout << endl;
        }
    }*/
 
    // find_the_day_max(max, input);
    stampa_array(numeri, count);
    // cout << "max: " << max << endl;
    // cout << "media:";
    // cout << fixed << setprecision(3) << media(totale, count) << endl;
    input.close();
    in.close();
    delete[] data;
    return 0;
}
bool is_a_number(char str)
{
    return (str >= '0' && str <= '9');
}
bool is_a_date(char *stringa)
{
    bool result = false;
    int giorno, mese, anno;
    if (estrai_data(stringa, giorno, mese, anno))
    {
        result = (giorno >= 1 && giorno <= 31) && (mese >= 1 && mese <= 12) && (anno >= 1950 && anno <= 2100);
        cout << "Giorno: " << giorno << " mese: ";
        leggi_mese(mese);
        cout << " anno:" << anno << endl;
    }
    return result;
}
bool estrai_data(char *str, int &giorno, int &mese, int &anno)
{
    bool result = false;
    if (is_a_number(str[0]) && is_a_number(str[1]))
    {
        char stringaGiorno[3] = {str[0], str[1], '\0'};
        giorno = atoi(stringaGiorno);
        if (str[2] == slash && is_a_number(str[3]) && is_a_number(str[4]))
        {
            char stringaMese[3] = {str[3], str[4], '\0'};
            mese = atoi(stringaMese);
            if (str[5] == slash && is_a_number(str[6]) && is_a_number(str[7]) && is_a_number(str[8]) && is_a_number(str[9]))
            {
                char stringaAnno[5] = {str[6], str[7], str[8], str[9], '\0'};
                anno = atoi(stringaAnno);
                result = true;
                str[10] = '\0';
            }
        }
    }
    return result;
}
void leggi_mese(int n)
{
    switch (n)
    {
    case 01:
        cout << "gennaio";
        break;
    case 02:
        cout << "febbraio";
        break;
    case 03:
        cout << "marzo";
        break;
    case 04:
        cout << "aprile";
        break;
    case 05:
        cout << "maggio";
        break;
    case 06:
        cout << "giugno";
        break;
    case 07:
        cout << "luglio";
        break;
    case 8:
        cout << "agosto";
        break;
    default:
        cout << "non valido " << endl;
        break;
    }
}
float media(int num, int howMany)
{
    return (float)num / howMany;
}
void stampa_array(int a[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << a[i];
        if(i!=dim-1)
        {
            cout << " - ";
        }
    }
    cout << endl;
}
/*void find_the_day_max(int max, fstream &testo, char *buffer)
{
    int n;
    char buffer[20];
    while (testo.eof())
    {
        testo >> buffer;
        if (is_a_date(buffer))
        {
            testo >> n;
            if (n == max)
            {
                cout << buffer << endl;
            }
        }
    }
}*/
int vett(int *&v, fstream &input, int count)
{
    char buffer[20];
    int number;
    int i;
    input >> buffer;
    if (is_a_date(buffer))
        {
            input >> number;
        }
    if (input.eof())
    {
        v = new int[count];
        i = count;
    }
    else
    {
 
        if (is_a_date(buffer))
        {
            i = vett(v, input, count + 1);
            v[count] = number;
        }
        else
        {
            i = vett(v, input, count);
        }
    }
    return i;
}