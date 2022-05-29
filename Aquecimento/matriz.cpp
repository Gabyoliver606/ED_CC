#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Pos{
    int l, c;
    Pos(int l, int c):
        l(l), c(c){}
    }

    bool operator==(Pos &pos){
        return l == pos.l && c == pos.c;
    }

    bool operator!=(Pos &pos){
        return l != pos.l || c != pos.c;
    }

    string str() {
        stringstream ss;
        ss << "(" << l << ", " << c << ")";
        return ss.str();
    }
};

ostream& operator<<(ostream &os, Pos &pos){
    os << pos.str();
    return os;
}

template <class T>
class matrix {
    int nl{0}, nc{0};
    std::vector<std::vector<T>> data;

public:
    
    matrix(int nl, int nc) : 
        nl(nl), nc(nc), data(nl, std::vector<T>(nc)) {
    }

   
    matrix(int nl, int nc, T def) : 
        nl(nl), nc(nc), data(nl, std::vector<T>(nc, def)) {
    }

 
    int nlines() {
        return nl;
    }


    int ncols() {
        return nc;
    }

  
    T& at(Pos pos) {
        return data[pos.l][pos.c];
    }

   
    T& operator[](Pos pos) {
        return at(pos);
    }

   
    std::vector<T> &operator[](int l) {
        return data[l];
    }

    
    bool inside(Pos pos) {
        return !(pos.l < 0 || pos.l >= nl || pos.c < 0 || pos.c >= nc);
    }


    bool is_value(Pos pos, char value) {
        return inside(pos) && at[pos] == value;
    }

    
    std::string str() {
        std::stringstream ss;
        for (int l = 0; l < nl; l++) {
            for (int c = 0; c < nc; c++)
                ss << (c == 0 ? "" : " ") << data[l][c];
            ss << '\n';
        }
        return ss.str();
    }
};

template <>
std::string matrix<char>::str() {

    std::stringstream ss;
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++)
            ss << data[l][c]; 
        ss << '\n';
    }
    return ss.str();
}

template <class T>
std::ostream& operator<<(std::ostream& os, matrix<T>& m) {
    return os << m.str();
}

int main() {
    {
        matrix<int> m(3, 4, 5);
        std::cout << m;
    }
    {
        matrix<char> m(3, 4, 'a');
        std::cout << m;
    }
    {
        matrix<int> m(3, 4);
        m[0][0] = 1; 
        m[{2, 2}] = 2; 
        std::cout << m;
        std::cout << m.inside({-1, 2}) << '\n';
        std::cout << m.is_value({2, 2}, 2) << '\n';
        std::cout << m.is_value({-1, 2}, 0) << '\n';
    }

}