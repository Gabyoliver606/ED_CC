#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector <int> pessoas;
    int tam, saiP, igual, aux;

    cin >> tam;

    for (int i = 0; i < tam; i++) {
        cin >> aux;
        pessoas.push_back(aux);
    }

    cin >> saiP;

    for (int i = 0; i < tam; i++) {
        if (pessoas[i] == saiP) {
            igual = 1;
            break;
        }
    }

    if (igual == 1) {
        for (int i = 0; i < tam; i++) {
            if (pessoas[i] != saiP) {
                cout << pessoas[i] << endl;
            }
        }
    } else {
        cout << "nao encontrado" << endl;
    }
    
    return 0;
}