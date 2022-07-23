#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Pos {
    int l, c;
    Pos(int l, int c) {
        this->l = l;
        this->c = c;
    }  
    bool operator==(Pos pos) {
        return l == pos.l && c == pos.c;
    }
    bool operator!=(Pos pos) {
        return l != pos.l || c != pos.c;
    }
    std::string str() {
        std::stringstream ss;
        ss << "(" << l << ", " << c << ")";
        return ss.str();
    }
};
std::ostream &operator<<(std::ostream &os, Pos pos) {
    return os << pos.str();
}

template <class T>
class Matriz {
    private:
        int nl, nc;
        vector<vector<T>> matriz;
    public:
        Matriz(int nl, int nc) {
            this->nl = nl;
            this->nc = nc;
            matriz.resize(nl);
            for (int i = 0; i < nl; i++) {
                matriz[i].resize(nc);
            }
        }
        Matriz(vector<vector<T>> matriz) {
            this->matriz = matriz;
            this->nl = matriz.size();
            this->nc = matriz[0].size();
        }
        Matriz(Matriz<T> matriz) {
            this->matriz = matriz.matriz;
            this->nl = matriz.nl;
            this->nc = matriz.nc;
        }
        int getNl() {
            return nl;
        }
        int getNc() {
            return nc;
        }
        T& operator()(int l, int c) {
            return matriz[l][c];
        }
        vector<T> operator[](int l) {
            return matriz[l];
        }
        bool inside(Pos pos) {
            return pos.l >= 0 && pos.l < nl && pos.c >= 0 && pos.c < nc;
        }
        bool is_value(Pos pos, T valor) {
            return matriz[pos.l][pos.c] == valor;
        }
        string str() {
            std::stringstream ss;
            for (int i = 0; i < nl; i++) {
                for (int j = 0; j < nc; j++) {
                    ss << matriz[i][j] << " ";
                }
                ss << endl;
            }
            return ss.str();
        }
};
template <>
    string Matriz<char>::str() {
        std::stringstream ss;
        for (int i = 0; i < nl; i++) {
            for (int j = 0; j < nc; j++) {
                ss << matriz[i][j] << " ";
            }
            ss << endl;
        }
        return ss.str();
    }
template <class T>
    std::ostream &operator<<(std::ostream &os, Matriz<T> matriz) {
        return os << matriz.str();
}

int main () {
    int nl, nc;
    cin >> nl >> nc;
    Matriz<int> matriz(nl, nc);
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            cin >> matriz(i, j);
        }
    }
    Matriz<int> rmatriz(nl, nc);
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            rmatriz(i, j) = matriz(nl - i - 1, nc - j - 1);
        }
    }
    int sum = 0;
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            sum += rmatriz(i, j);
        }
    }
    int mult = 1;
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            mult *= rmatriz(i, j);
        }
    }
    int max = rmatriz(0, 0);
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            if (rmatriz(i, j) > max) {
                max = rmatriz(i, j);
            }
        }
    }
    int min = rmatriz(0, 0);
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            if (rmatriz(i, j) < min) {
                min = rmatriz(i, j);
            }
        }
    }
    stringstream ss;
    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++) {
            ss << rmatriz(i, j) << " ";
        }
        ss << endl;
    }
    cout << ss.str() << endl;
    cout << sum << endl;
    cout << mult << endl;
    cout << max << endl;
    cout << min << endl;
    return 0;
}


