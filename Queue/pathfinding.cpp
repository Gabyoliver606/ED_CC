#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Pos {
    int x;
    int y;
};

vector <Pos> get_vizinhos(Pos pos) {
    return {Pos{pos.x, pos.y - 1}, Pos{pos.x, pos.y + 1}, Pos{pos.x - 1, pos.y}, Pos{pos.x + 1, pos.y}};
}

void go_back(vector<string> &mat, vector<vector<int>> &dist, Pos pos, int value){
    if(get(mat, pos) != 'x' || get(dist, pos) != value) 
        return;
    get(mat, pos) = '.';
    for(Pos viz : get_vizinhos(pos))
        go_back(mat, dist, viz, value - 1); 
}

bool procurar_saida (vector <string> &matrix, Pos inicio, Pos fim) {
    vector <Pos> pilha;
    pilha.push_back(inicio);
    while (!pilha.empty()) {
        auto top = pilha.back();
        pilha.pop_back();
        if(top.x == fim.x && top.y == fim.y)
            return true;
        for (auto vizinho : get_vizinhos(top)) {
            if (get(matrix, vizinho) == '#') {
                set(matrix, vizinho, 'o');
                pilha.push_back(vizinho);
            }
        }
    }
    return false;
}

void remover_erros (vector <string> &matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 'o') {
                matrix[i][j] = '#';
            }
        }
    }
}

int main () {
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); 
    getchar();
    Pos inicio, fim;
    
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);
    
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
        }
    }
    
    vector<vector<int>> dist(nl, vector<int>(nc, 0));
    vector<vector<bool>> visited(nl, vector<bool>(nc, false));
    list<Pos> q;
    q.push_back(inicio);
    visited[inicio.x][inicio.y] = true;
    int value = 0;
    while(!q.empty()){
        Pos top = q.front();
        q.pop_front();
        if(top.x == fim.x && top.y == fim.y)
            break;
        for(Pos viz : get_vizinhos(top)){
            if(!visited[viz.x][viz.y] && get(matrix, viz) == '#'){
                visited[viz.x][viz.y] = true;
                q.push_back(viz);
                set(dist, viz, value);
            }
        }
        value++;
    }
    go_back(matrix, dist, fim, get(dist, fim));
    remover_erros(matrix);
    cout << value << endl;
    return 0;
}










