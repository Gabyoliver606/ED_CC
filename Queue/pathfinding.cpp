#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>

struct Pos {
    int l;
    int c;
};

#define get(mat, pos) mat[pos.l][pos.c]

std::vector<Pos> get_vizinhos(Pos p) {
    std::vector<Pos> vizinhos = {
        {p.l - 1, p.c},
        {p.l + 1, p.c},
        {p.l, p.c - 1},
        {p.l, p.c + 1}
    };
    return vizinhos;
}

void refazer (std::vector<std::string> &mat, Pos p) {
    std::vector<Pos> vizinhos = get_vizinhos(p);
    for (auto vizinho : vizinhos) {
        if (get(mat, vizinho) == '#') {
            mat[vizinho.l][vizinho.c] = 'o';
            refazer(mat, vizinho);
        }
    }
}

bool procurar_saida (std::vector<std::string> &mat, Pos inicio, Pos fim) {
    std::vector<Pos> pilha;
    pilha.push_back(inicio);
    while (!pilha.empty()) {
        auto top = pilha.back();
        pilha.pop_back();
        if(top.l == fim.l && top.c == fim.c)
            return true;
        for (auto vizinho : get_vizinhos(top)) {
            if (get(mat, vizinho) == '#') {
                mat[vizinho.l][vizinho.c] = 'o';
                pilha.push_back(vizinho);
            }
        }
    }
    return false;
}

void remover_erros (std::vector<std::string> &mat) {
    Pos saida;
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == 'o') {
                mat[i][j] = '#';
            }
        }
    }
}

int main() {
    int nl = 0, nc = 0;
    std::cin >> nl >> nc;
    std::vector<std::string> mat(nl, ""); 
    std::getchar();
    Pos inicio, fim;
    for(int i = 0; i < nl; i++)
        std::getline(std::cin, mat[i]);
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
        }
    }
    if (procurar_saida(mat, inicio, fim)) {
        refazer(mat, inicio);
        remover_erros(mat);
        std::cout << "S";
        for (size_t i = 0; i < mat.size(); i++) {
            for (size_t j = 0; j < mat[0].size(); j++) {
                std::cout << mat[i][j];
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "N";
    }
    return 0;
}