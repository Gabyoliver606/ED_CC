#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> read_vector() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> v;
    int x;
    while (iss >> x) {
        v.push_back(x);
    }
    return v;
}

void parcial_print(vector<int>& v, int n, int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) {
            cout << v[j] << " ";
        }
        cout << endl;
        return;
    }
    v[i] = 0;
    parcial_print(v, n, i + 1);
    v[i] = 1;
    parcial_print(v, n, i + 1);
}

void show_vector(vector<int>& v, int n) {
    parcial_print(v, n, 0);
}

void show_reverse_vector(vector<int>& v, int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int soma_vector(vector<int>& v, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += v[i];
    }
    return s;
}

int multiplica_vector(vector<int>& v, int n) {
    int m = 1;
    for (int i = 0; i < n; i++) {
        m *= v[i];
    }
    return m;
}

int min_vector(vector<int>& v, int n) {
    int m = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < m) {
            m = v[i];
        }
    }
    return m;
}

void reverse(vector<int>& v, int n) {
    for (int i = 0; i < n / 2; i++) {
        int aux = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = aux;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    show_vector(v, n);
    show_reverse_vector(v, n);
    cout << soma_vector(v, n) << endl;
    cout << multiplica_vector(v, n) << endl;
    cout << min_vector(v, n) << endl;
    reverse(v, n);
    show_vector(v, n);
    return 0;
}
