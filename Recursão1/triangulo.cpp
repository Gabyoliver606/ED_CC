#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


void print(vector<int> vet){
    cout << "[";
    for(auto x : vet)
        cout << " " << x;
    cout << " ]\n";
}

void processar(vector<int> vet){
   if(vet.size() == 1)
       return;
    int i = 0;
    while(i < vet.size()){
        if(vet[i] == 0)
            vet.erase(vet.begin() + i);
        else
            i++;
    }
}

int main () {
    vector<int> vet;
    string line;
    while(getline(cin, line)){
        istringstream iss(line);
        int x;
        while(iss >> x)
            vet.push_back(x);
        processar(vet);
        print(vet);
        vet.clear();
    }
    return 0;
}