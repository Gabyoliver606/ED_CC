#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Vector{
    int capacity {0};
    int size {0};
    int *data {nullptr};
    Vector(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->data = new int[capacity];
    }
   
    Vector operator +(Vector v){
        Vector result(this->capacity + v.capacity);
        for(int i = 0; i < this->size; i++){
            result.data[i] = this->data[i];
        }
        for(int i = 0; i < v.size; i++){
            result.data[i + this->size] = v.data[i];
        }
        result.size = this->size + v.size;
        return result;
    }

    Vector (const Vector &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->data = new int[other.capacity];
        for(int i = 0; i < other.size; i++){
            this->data[i] = other.data[i];
        }
    }
    ~Vector(){
        delete[] this->data;
    }
};

int main () {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int n;
    ss >> n;
    Vector v(n);
    getline(cin, line);
    stringstream ss2(line);
    int x;
    while(ss2 >> x){
        v.data[v.size] = x;
        v.size++;
    }
    getline(cin, line);
    stringstream ss3(line);
    int m;
    ss3 >> m;
    Vector v2(m);
    getline(cin, line);
    stringstream ss4(line);
    int x2;
    while(ss4 >> x2){
        v2.data[v2.size] = x2;
        v2.size++;
    }
    Vector result = v + v2;
    for(int i = 0; i < result.size; i++){
        cout << result.data[i] << endl;
    }
    return 0;
}