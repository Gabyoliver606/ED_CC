#include <iostream>
#include <list>
#include <sstream>

using namespace std;

struct State {
    list <char> text;
    list <char>::iterator cursor;
    State(){
        cursor = text.begin();
    }

    State(string init) {
        for (int i = 0; i < init.size(); i++) {
            text.push_back(init[i]);
        }
        cursor = text.begin();
    }

    State(const State& other) {
        text = other.text;
        cursor = other.cursor;
    }

    string getText() {
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

    void controlZ() {
        if (itc != states.begin()) {
            itc--;
        }
    }

    void controlY() {
        if (itc != states.end()) {
            itc++;
        }
    }

    void insertchar(char c) {
        itc->text.insert(itc->cursor, c);
        itc->cursor++;
    }

    void sendBackspace() {
        if (itc->cursor != itc->text.begin()) {
            itc->text.erase(itc->cursor--);
        }
    }

    void sendDelete() {
        if (itc->cursor != itc->text.end()) {
            itc->text.erase(itc->cursor++);
        }
    }

    void sendUp() {
        int desloc = 0;
        auto it = itc->cursor;

        while(((*prev(it)) != '\n') && (prev(it) != itc->text.end())){
            desloc++;
            it--;
        }
       
        if(prev(it) != itc->text.end()){
            
            do{
                it--;
            }while(((*prev(it)) != '\n') && (prev(it) != itc->text.end()));
          
            for(int i = 0; i < desloc; i++){
                if(((*it) == '\n') || (it == itc->text.end()))
                    break;
                else
                    it++;
            }
            itc->cursor = it;
        }
    }

    void sendDown() {
        int desloc = 0;
        auto it = itc->cursor;
        while(((*next(it)) != '\n') && (next(it) != itc->text.end())){
            desloc++;
            it++;
        }
        if(next(it) != itc->text.end()){
            do{
                it++;
            }while(((*next(it)) != '\n') && (next(it) != itc->text.end()));
            for(int i = 0; i < desloc; i++){
                if(((*it) == '\n') || (it == itc->text.end()))
                    break;
                else
                    it++;
            }
            itc->cursor = it;
        }
    }

    void sendLeft() {
        if (itc->cursor != itc->text.begin()) {
            itc->cursor--;
        }
    }

    void sendRight() {
        if (itc->cursor != itc->text.end()) {
            itc->cursor++;
        }
    }
};

void processKey(Ambiente& ambiente, char tecla) {
   if (tecla == 'z')
        ambiente.controlZ();
    else if (tecla == 'y')
        ambiente.controlY();
    else if (tecla == 'B')
        ambiente.sendBackspace();
    else if (tecla == 'D')
        ambiente.sendDelete();
    else if (tecla == 'U')
        ambiente.insertchar('\n');
    else if (tecla == 'L')
        ambiente.insertchar('\t');
    else if (tecla == 'A') {
        ambiente.sendUp();
    } else if (tecla == 'V') {
        ambiente.sendDown();
    } else if (tecla == '<') {
        ambiente.sendLeft();
    } else if (tecla == '>') {
        ambiente.sendRight();
    } else {
        ambiente.insertchar(tecla);
    }
}

int main () {
    string init_text;
    cin >> init_text;
    Ambiente ambiente(init_text);
    char tecla;
    while (cin >> tecla) {
        processKey(ambiente, tecla);
        cout << ambiente.itc->getText() << endl;
    }
    return 0;
}