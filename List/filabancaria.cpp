#include <iostream> 
#include <list>
#include <iterator>
#include <vector>
#include <sstream>

using namespace std;

struct Cliente {
    string nome;
    int actions;
    int patience;

    Cliente(string nome, int actions, int patience) {
        this->nome = nome;
        this->actions = actions;
        this->patience = patience;
    }
    string toString() {
        return nome + " " + to_string(actions) + " " + to_string(patience);
    }
};

struct Banco {
    vector<Cliente*> teller;
    list<Cliente*> fila;
    list<Cliente*> fila_espera;
    int received {0};
    int lost {0};
    int tics {0};

    Banco(int teller_size) {
       teller = vector<Cliente*>(teller_size);
    }

    void insert(Cliente* cliente) {
        fila.push_back(cliente);
    }

    bool empty() {
        for(auto it = teller.begin(); it != teller.end(); it++) {
            if(*it != nullptr) return false;
        }
        return true;
    }

    void tic() {
        tics++;
        while(!fila.empty()) {
            Cliente* cliente = fila.front();
            fila.pop_front();
            if(cliente->patience > 0) {
                fila_espera.push_back(cliente);
            } else {
                lost++;
            }
        }
        while(!fila_espera.empty()) {
            Cliente* cliente = fila_espera.front();
            fila_espera.pop_front();
            fila.push_back(cliente);
        }
    }

    void show() {
        cout << "Tic: " << tics << endl;
        cout << "Received: " << received << endl;
        cout << "Lost: " << lost << endl;
        cout << "Fila: " << fila.size() << endl;
        cout << "Fila Espera: " << fila_espera.size() << endl;
        cout << "Teller: " << endl;
        for(auto it = teller.begin(); it != teller.end(); it++) {
            if(*it != nullptr) {
                cout << (*it)->toString() << endl;
            }
        }
        cout << endl;
    }
};

int main() {
    Banco banco(3);
    
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "exit") {
            break;
        } else if(cmd == "insert") {
            string nome;
            int actions, patience;
            ss >> nome >> actions >> patience;
            Cliente* cliente = new Cliente(nome, actions, patience);
            banco.insert(cliente);
        } else if(cmd == "tic") {
            banco.tic();
        } else if(cmd == "show") {
            banco.show();
        }
    }
    return 0;
}

