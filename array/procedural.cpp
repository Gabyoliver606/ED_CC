#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Vector{
    int capacity;
    int size;
    int *data;
};

Vector *createVector(int capacity){
    Vector *v = new Vector;
    v->capacity = capacity;
    v->size = 0;
    v->data = new int[capacity];
    return v;
}

void destroyVector(Vector *v){
    delete[] v->data;
    delete v;
}

void addVector(Vector *v, int value){
    if(v->size == v->capacity){
        v->capacity *= 2;
        int *newData = new int[v->capacity];
        for(int i = 0; i < v->size; i++){
            newData[i] = v->data[i];
        }
        delete[] v->data;
        v->data = newData;
    }
    v->data[v->size] = value;
    v->size++;
}

string vector_show(Vector *v){
    string s = "";
    for(int i = 0; i < v->size; i++){
        s += to_string(v->data[i]) + " ";
    }
    return s;
}

int main(){
    string line, cmd;
    int value;
    Vector *v = createVector(1);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "add"){
            ss >> value;
            addVector(v, value);
        }else if(cmd == "show"){
            cout << vector_show(v) << endl;
        }else if(cmd == "exit"){
            destroyVector(v);
            break;
        }
    }
    return 0;
}
