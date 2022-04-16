#include <iostream>
#include <vector>

using namespace std;

void tocar_fogo(vector<int>& v, int n, int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) {
            cout << v[j] << " ";
        }
        cout << endl;
        return;
    }
    v[i] = 0;
    tocar_fogo(v, n, i + 1);
    v[i] = 1;
    tocar_fogo(v, n, i + 1);
}

void imprimir_fogo(vector<int>& v, int n) {
    tocar_fogo(v, n, 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    imprimir_fogo(v, n);
    return 0;
}