#include <iostream>
#include <vector>

using namespace std;

struct Pos {
    int x;
    int y;
};

vector <Pos> get_vizinhos(Pos pos, int size) {
    return {Pos{pos.x, pos.y - 1}, Pos{pos.x, pos.y + 1}, Pos{pos.x - 1, pos.y}, Pos{pos.x + 1, pos.y}};
}

bool procurar_saida (vector <string> &matrix, Pos inicio, Pos fim) {
    vector <Pos> pilha;
    pilha.push_back(inicio);
    while (!pilha.empty()) {
        auto top = pilha.back();
        pilha.pop_back();
        if(top.x == fim.x && top.y == fim.y)
            return true;
        for (auto vizinho : get_vizinhos(top, matrix.size())) {
            if (matrix[vizinho.x][vizinho.y] == '#') {
                matrix[vizinho.x][vizinho.y] = 'o';
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
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }
    procurar_saida(mat, inicio, fim);
    remover_erros(mat);
    for(string line : mat)
        cout << line << endl;
    return 0;
}
