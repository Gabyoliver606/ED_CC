#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

std::vector<int> read_vector() {
    std::string line;
    std::vector<int> vet;
    int input;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    
    while (ss >> input) {
        vet.push_back(input);
    }

    return vet;
}

void partial_print(const std::vector<int>& vet, int pos, bool start_condition, bool end_condition, const std::string& label) {
    if (start_condition) {
        std::cout << label <<" : [ ";
    }

    std::cout << vet[pos];

    if (end_condition) {
        std::cout << " ]" << std::endl;
    } else {
        std::cout << " ";
    }
}

void show_vector(const std::vector<int>& vet, int pos = 0) {
    if (pos == vet.size()) {
        return;
    }

    partial_print(vet, pos, pos == 0, pos == vet.size() - 1, "vet");
    show_vector(vet, pos + 1);
}

void show_reverse_vector(const std::vector<int>& vet, int pos = 0) {
    if (pos >= vet.size()) {
        return;
    }

    show_reverse_vector(vet, pos + 1);
    partial_print(vet, pos, pos == vet.size() - 1, pos == 0, "rvet");
}

int sum(const std::vector<int>& vet, int pos = 0) {
    if (pos >= vet.size()) {
        return 0;
    }

    return vet[pos] + sum(vet, pos + 1);
}

int mult(const std::vector<int>& vet, int pos = 0) {
    if (pos >= vet.size()) {
        return 1;
    }

    return vet[pos] * mult(vet, pos + 1);
}

int min(const std::vector<int>& vet, int pos = 0, int min_pos = 0) {
    if (pos >= vet.size()) {
        return min_pos;
    }

    if (vet[pos] < vet[min_pos]) {
        min_pos = pos;
    }

    return pos == 0 ? vet[min(vet, pos + 1, min_pos)] : min(vet, pos + 1, min_pos);
}

void reverse(std::vector<int>& vet, int pos = 0) {
    if (pos >= vet.size() / 2) {
        return;
    }

    std::swap(vet[pos], vet[vet.size() - 1 - pos]);
    reverse(vet, pos + 1);
}

int main() {
    auto vet = read_vector();

    show_vector(vet);
    show_reverse_vector(vet);
    std::cout << "sum: " << sum(vet) << std::endl;
    std::cout << "mult: " << mult(vet) << std::endl;
    std::cout << "min: " << min(vet) << std::endl;
    reverse(vet);
    show_vector(vet);
}

/*vector<int> read_vector() {
    string line;
    vector<int> vet;
    int input;
    getline(std::cin, line);
    stringstream ss(line);
    
    while (ss >> input) {
        vet.push_back(input);
    }

    return vet;
}


void partial_print(const vector <int>& v, int pos, bool start_condition, bool end_condition, const string& label) {
    if (start_condition) {
        cout << label << ": ";
    }

    cout << v[pos];

    if (end_condition) {
        cout << endl;
    }
}

void show_vector (const vector <int>& v, int pos = 0) {
   if(pos >= v.size()) {
       return;
   }

   partial_print(v, pos, pos == 0, pos == v.size() - 1, "vector");
    show_vector(v, pos + 1);

}

void show_vector_reverse (const vector <int>& v, int pos = 0) {
   if(pos >= v.size()) {
       return;
   }

   partial_print(v, pos, pos == 0, pos == v.size() - 1, "rvector");
    show_vector_reverse(v, pos + 1);

}

int soma(const vector <int>& v, int pos = 0) {
    if(pos >= v.size()) {
        return 0;
    }

    return v[pos] + soma(v, pos + 1);
}

int mult(const vector <int>& v, int pos = 0) {
    if(pos >= v.size()) {
        return 1;
    }

    return v[pos] * mult(v, pos + 1);
}

int min(const vector <int>& v, int pos = 0, int min_pos = 0) {
    if(pos >= v.size()) {
        return min_pos;
    }

    if(v[pos] < v[min_pos]) {
        min_pos = pos;
    }

    return min(v, pos + 1) < v[pos] ? min(v, pos + 1) : v[pos];
}

int reverse(const vector <int>& v, int pos = 0) {
    if(pos >= v.size() / 2) {
        return;
    }

    swap(v[pos], v[v.size() - pos - 1]);
    reverse(v, pos + 1);
}

int main() {
    int n;
    cin >> n;
    vector <int> v = read_vector(n);
    show_vector(v);
    show_vector_reverse(v);
    cout << "soma: " << soma(v) << endl;
    cout << "mult: " << mult(v) << endl;
    cout << "min: " << min(v) << endl;
    cout << "reverse: " << endl;
    reverse(v);
    show_vector(v);
    return 0;
}*/