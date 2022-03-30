#include <iostream>
#include <list>

using namespace std;

void show_list(list<int>& l, list<int>::iterator& espada){
    for(auto it = l.begin(); it != l.end(); it++){
        cout << *it << (it == espada? "> " : "  ");
    }
    cout << endl;
}

int main(){
    int size{}, espada{};
    cin >> size >> espada;
    list<int> l;
    for(int i = 0; i < size; i++){
        l.push_back(i + 1);
    
    auto it_espada = next(l.begin(), espada - 1);
    auto fix_espada_loop = [&l](auto it){
        if(it == l.end()){
            it = l.begin();
        }
    };
    while(l.size() > 1){
        show_list(l, it_espada);
        it_espada = next(it_espada, 1);
        l.erase(it_espada);
        fix_espada_loop(it_espada);
    }
    cout << *l.begin() << endl;
    }
}



