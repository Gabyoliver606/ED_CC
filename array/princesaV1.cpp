#include <iostream>
#include <vector>

using namespace std;

const int MORTO = 0;

int achar_pxm_vivo(int vet[], int size, int pos) {
    int pos = (pos + 1) % size;
    while (vet[pos] == MORTO) {
        pos = (pos + 1) % size;
    return pos;
    }
}

void mostrar_vetor(int vet[], int size, int elemento){ 
    int pos = achar_pxm_vivo(vet, size, elemento);
    for (int i = 0; i < size; i++) {
        if (i == pos) {
            cout << "*";
        } else {
            cout << vet[i];
        }
    }
    cout << endl;
}

int main() {
    int size, elemento;
    cin >> size >> elemento;
    int vet[size];
    for (int i = 0; i < size; i++) {
        cin >> vet[i];
    }
    mostrar_vetor(vet, size, elemento);
    return 0;
}