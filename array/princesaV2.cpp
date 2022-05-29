#include <iostream>
#include <vector>

using namespace std;

const int MORTO = 0;

int walk(int pos, int size, int dir) {
    if(dir == 1)
        return (pos + 1) % size;
    return (pos - 1 + size) % size;
}

int achar_pxm_vivo(int vet[], int size, int pos, int dir) {
    int pos = walk(pos, size, dir);
    while (vet[pos] == MORTO)
        pos = walk(pos, size, dir);
    return pos;
}

void mostrar_vetor(int vet[], int size, int elemento){ 
    for (int i = 0; i < size; i++) {
        if (vet[i] != MORTO) {
            cout << " ";
        } if((i == elemento) && (vet[i] < 0)) {
            cout << "<";
            cout << vet[i];
        } if((i == elemento) && (vet[i] > 0)) {
            cout << ">";
            cout << vet[i];
        }
    }
    cout << endl;
}
int main(){
    int size = 0;
    int elemento = 0;
    int fase = 0;
    cin >> size >> elemento >> fase;
    int vet[size];
    for (int i = 0; i < size; i++) {
        vet[i] = (i + 1) * fase;
        fase *= -1
}
    elemento = elemento - 1;
    mostrar_vetor(vet, size, elemento);
    int qtd = size - 1;
    while(qtd--) {
        int dir = vet[elemento] > 0 ? 1 : -1;
        int vai_morrer = achar_pxm_vivo(vet, size, elemento, dir);
        vet[vai_morrer] = 0;
        elemento = achar_pxm_vivo(vet, size, vai_morrer, dir);
        mostrar_vetor(vet, size, elemento);
    }
}