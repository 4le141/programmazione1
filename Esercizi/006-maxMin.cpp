#include <iostream>

using namespace std;

int main (int argc, char* argv[]){
    int a,b, max, min;
    cout<<"Inserisci due numeri interi a e b: ";
    cin>>a>>b;
    max = a*(a>=b) + b*(a<b);
    min = a+b-max;
    cout<<"Max = "<<max<<endl<<"Min = "<<min<<endl;
    return 0;
}