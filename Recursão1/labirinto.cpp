#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

vector<Point> get_vizinhos(vector<vector<char>>& labirinto, Point& p) {
    vector<Point> vizinhos;
    if (p.x > 0 && labirinto[p.x - 1][p.y] != '#') {
        vizinhos.push_back({p.x - 1, p.y});
    }
    if (p.x < labirinto.size() - 1 && labirinto[p.x + 1][p.y] != '#') {
        vizinhos.push_back({p.x + 1, p.y});
    }
    if (p.y > 0 && labirinto[p.x][p.y - 1] != '#') {
        vizinhos.push_back({p.x, p.y - 1});
    }
    if (p.y < labirinto[0].size() - 1 && labirinto[p.x][p.y + 1] != '#') {
        vizinhos.push_back({p.x, p.y + 1});
    }
    return vizinhos;
}

int main() {
    int linhas, colunas;
    cin >> linhas >> colunas;
    vector<vector<char>> labirinto(linhas, vector<char>(colunas));
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> labirinto[i][j];
        }
    }
    Point inicio;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (labirinto[i][j] == 'I') {
                inicio = {i, j};
            }
        }
    }
    vector<Point> caminho;
    vector<Point> vizinhos = get_vizinhos(labirinto, inicio);
    while (vizinhos.size() > 0) {
        Point p = vizinhos[0];
        vizinhos.erase(vizinhos.begin());
        if (labirinto[p.x][p.y] == 'F') {
            caminho.push_back(p);
            break;
        }
        labirinto[p.x][p.y] = '.';
        vizinhos.insert(vizinhos.end(), get_vizinhos(labirinto, p).begin(), get_vizinhos(labirinto, p).end());
        caminho.push_back(p);
    }
    for (auto p : caminho) {
        labirinto[p.x][p.y] = '.';
    }
    for (auto linha : labirinto) {
        for (auto c : linha) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}

