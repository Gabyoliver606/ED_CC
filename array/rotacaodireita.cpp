#include <iostream>
#include <vector>

using namespace std;

void right_rotation (vector<int>& vet, int nrot) {
    int n = vet.size();
    for (int i = 0; i < nrot; i++) {
        int aux = vet[n - 1];
        for (int j = n - 1; j > 0; j--) {
            vet[j] = vet[j - 1];
        }
        vet[0] = aux;
    }
}

void show_vector (vector<int>& vet) {
    for (int i = 0; i < vet.size(); i++) {
        cout << vet[i] << " ";
    }
    cout << endl;
}

int main () {
    int n;
    cin >> n;
    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }
    int nrot;
    cin >> nrot;
    right_rotation(vet, nrot);
    show_vector(vet);
    return 0;
}
    