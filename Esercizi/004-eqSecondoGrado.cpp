#include <iostream>
#include <cmath>

using namespace std;

int main (int argc, char* argv[]){
    double a,b,c;
    cout<<"Inserisci a, b e c (a*(x^2) + b*x + c): ";
    cin>>a>>b>>c;
    if (a==0){
        if (b==0){
            if (c==0){
                cout<<"Infinite soluzioni"<<endl;
            }else{
                cout<<"Equazione impossibile"<<endl;
            }
        }else{
            if (c==0){
                cout<<"La soluzione è 0" << endl;
            }else{
                cout<<"La soluzione è " << (-(c/b)) << endl;
            }
        }
    }else{
        double delta;
        delta=(b*b)-(4*a*c);
        if (delta<0){
            cout<<"L'equazione non ha soluzioni in R"<<endl;
        }else if (delta==0){
            cout<<"X equivale a: "<<-b/(2*a)<<endl;
        }else if (delta>0){
            cout<<"X1 equivale a: "<<(-b+sqrt(delta))/(2*a)<<"\n";
            cout<<"X2 equivale a: "<<(-b-sqrt(delta))/(2*a)<<endl;
         }
    }
    return 0;
}