#include <iostream>
#include <vector>

using namespace std;

void show_vet(vector<int> vet, int espada){
  for(int i = 0; i < (int) vet.size(); i++){
    cout << vet[i] << (i == espada? "> " : "  ");
  }
  cout << endl;
}

int achar_vivo(vector<int>& vet, int pos){
   do {
    pos = (pos + 1) % vet.size();
    } while(vet[pos] == false);
    return pos;
}

int main(){
    int size{}, espada{};
    cin >> size >> espada;
    vector<int> v(size, true);
    espada -= 1;
    int qtd = v.size() - 1;
    while(qtd >= 0){
        if(v[qtd] == true){
            v[qtd] = false;
            espada -= 1;
            if(espada == 0){
                cout << qtd + 1;
                return 0;
            }
        }
        qtd--;
    }
    
}