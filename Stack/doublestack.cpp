#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct F2P {
    stack<int> armazem;
    stack<int> colheita;
} Fila;

int main () {
    int n, m;
    cin >> n >> m;
    vector <Fila> filas(n);
    for (int i = 0; i < m; i++) {
        int f, c;
        cin >> f >> c;
        filas[f].armazem.push(c);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int f, c;
        cin >> f >> c;
        filas[f].colheita.push(c);
    }
    int s;
    cin >> s;
    int cont = 0;
    for (int i = 0; i < s; i++) {
        int f, c;
        cin >> f >> c;
        while (!filas[f].armazem.empty()) {
            if (filas[f].armazem.top() == c) {
                filas[f].armazem.pop();
                cont++;
                break;
            } else {
                filas[f].armazem.pop();
            }
        }
    }
    cout << cont << endl;
    return 0;
}


