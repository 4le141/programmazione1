#include <iostream>
#include <fstream>

using namespace std;

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

    input.close();
    output.close();
  
  return 0;
}