#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

template <class T>
vector<T> range(T init, T finish) {
    vector<T> output;
    for (T i = init; i < finish; i++)
        output.push_back(i);
    return output;
}

template <class T>
vector<T> shuffle(vector<T> input) {
    random_shuffle(input.begin(), input.end());
    return input;
}

struct Problema {
    string data;
    int lim;
    vector<int> holes;

    Problema(string data, int lim) {
        this->data = data;
        this->lim = lim;
        for (int i = 0; i < data.size(); i++)
            if (data[i] == '.')
                holes.push_back(i);
    }

    bool fit(int pos, int size) {
        for (int i = pos; i < pos + size; i++) {
            if (i >= data.size() || data[i] != '.')
                return false;
        }
        return true;
    }

    bool solve(int hindex) {
        if (hindex == holes.size()) {
            return true;
    }

    auto index = holes[hindex];

    auto values = shuffle(range<char>('0', '0' + lim + 1));
        for (char v : values) {
            if (this->fit(index, v)) {
                this->data[index] = v;
                if (this->solve(hindex + 1))
                    return true;
            }
        }
        data[index] = '.';
        return false;
    }

    string str () {
        stringstream ss;
        for (auto line : data)
            ss << line;
        return ss.str();
    }
};

int main () {
    auto& input = cin;

    int size { };
    input >> size;
    vector<string> data(size);
    for (int i = 0; i < size; i++)
        input >> data[i];
    
    Problem prob(data);
    prob.solve(0);
    std::cout << prob.str();
}
