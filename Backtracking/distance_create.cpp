#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;

struct State{
    list <char> text;
    list <char>::iterator cursor;

    State(){
        cursor = text.begin();
    }

    State(string init){
        for (int i = 0; i < init.size(); i++) {
            text.push_back(init[i]);
        }
        cursor = text.begin();
    }

    State(const State& other){
        text = other.text;
        cursor = other.cursor;
    }

    string getText(){
        stringstream ss;
        for (auto it = text.begin(); it != text.end(); it++) {
            ss << *it;
        }
        return ss.str();
    }
};

struct Ambiente {
    list <State> states;
    list <State>::iterator itc;

    Ambiente(string init_text = "") {
        states.push_back(State(init_text));
        itc = states.begin();
    }

    void controlZ(){
        if (itc != states.begin()) {
            itc--;
        }
    }

    void controlY(){
        if (itc != states.end()) {
            itc++;
        }
    }

    void insertchar(char c){
        itc->text.insert(itc->cursor, c);
        itc->cursor++;
    }

    void moverCursor(char c){
        if (c == 'l'){
            if (itc->cursor != itc->text.begin()){
                itc->cursor--;
            }
        }
        else if (c == 'r'){
            if (itc->cursor != itc->text.end()){
                itc->cursor++;
            }
        }
    }
};

int main () {
    Ambiente ambiente;
    string comando;
    while (getline(cin, comando)){
        if (comando == "z"){
            ambiente.controlZ();
        }
        else if (comando == "y"){
            ambiente.controlY();
        }
        else if (comando == "i"){
            char c;
            cin >> c;
            ambiente.insertchar(c);
        }
        else if (comando == "m"){
            char c;
            cin >> c;
            ambiente.moverCursor(c);
        }
        else if (comando == "q"){
            break;
        }
        cout << ambiente.itc->getText() << endl;
    }
    return 0;
}

