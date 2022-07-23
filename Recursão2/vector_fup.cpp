#include <iostream>
#include <sstream>

using namespace std;

struct Vector{
    int capacity;
    int size;
    int * data;
};

Vector * createVector(int capacity){
    Vector * vector = new Vector;
    vector->capacity = capacity;
    vector->size = 0;
    vector->data = new int[capacity];
    return vector;
}

void destroyVector(Vector * vector){
    delete [] vector->data;
    delete vector;
}

void add(Vector * vector, int element){
    if(vector->size == vector->capacity){
        vector->capacity *= 2;
        int * newData = new int[vector->capacity];
        for(int i = 0; i < vector->size; i++){
            newData[i] = vector->data[i];
        }
        delete [] vector->data;
        vector->data = newData;
    }
    vector->data[vector->size] = element;
    vector->size++;
}

string show(Vector * vector){
    stringstream ss;
    for(int i = 0; i < vector->size; i++){
        ss << vector->data[i];
    }
    return ss.str();
}

int main() {
    string line, cmd;
    int n, element;
    Vector * vector = createVector(10);
    while(getline(cin, line)){
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "add"){
            ss >> element;
            add(vector, element);
        } else if(cmd == "show"){
            cout << show(vector) << endl;
        } else if(cmd == "destroy"){
            destroyVector(vector);
        }
    }
    return 0;
}

