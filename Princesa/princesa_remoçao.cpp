#include <iostream>
#include <vector>

using namespace std;

void show_vet(vector<int> vet, int espada){
  for(int i = 0; i < (int) vet.size(); i++){
    cout << vet[i] << (i == espada? "> " : "  ");
  }
  cout << endl;
}

int main(){
    int size{}, espada{};
    cin >> size >> espada;
    vector<int> v(size);
    for(int i = 0; i < size; i++){
        v[i] = i + 1;
    espada -= 1;
    int qtd = v.size() - 1;
    while(qtd --){
        show_vet(v, espada);
        espada = (espada + 1) % v.size();
        v.erase(v.begin() + espada);
        espada = (espada + 1) % v.size();
    }
    cout << v[0] << endl;
    }
}