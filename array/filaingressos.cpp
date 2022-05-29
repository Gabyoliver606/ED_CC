#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> pessoas;
    int tam, saiP, igual, aux;

    cin >> tam;

    for(int i = 0; i < tam; i++){
        cin >> saiP;
        pessoas.push_back(saiP);
    }

    cin >> saiP;

    for(int i = 0; i < tam; i++){
        if(pessoas[i] == saiP){
            igual = i;
        }
    }

    for(int i = 0; i < tam; i++){
        if(i != igual){
            aux = pessoas[i];
            pessoas[i] = pessoas[igual];
            pessoas[igual] = aux;
            igual++;
        }
    }
}