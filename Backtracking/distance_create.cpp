#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <optional>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

const char EMPTY = '.';

template<class T>
    vector<T> range(T begin, T end) {
        vector<T> result;
        for (T i = begin; i < end; i++) {
            result.push_back(i);
        }
        return result;
    }

struct Problema {
    string data;
    int lim;
    vector<int> holes;

    Problema(string data, int lim) {
        this->data = data;
        this->lim = lim;
        for (int i = 0; i < data.size(); i++) 
            if (data[i] == EMPTY) 
                holes.push_back(i);
    }

    bool fit(int pos, int size) {
        for (int i = pos; i < pos + size; i++) {
            if (i >= data.size() || data[i] != EMPTY)
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
        data[index] = EMPTY;
        return false;
    }

     int count_solutions(int hindex) {
        if (hindex == (int) this->holes.size())
            return true;
        //
        auto index = holes[hindex];
        //
        int solutions = 0;
        auto values = shuffle(range<char>('0', '0' + lim + 1));
        for (char v : values) {
            if (this->fit(index, v)) {
                this->data[index] = v;
                solutions += count_solutions(hindex + 1);
            }
        }
        data[index] = EMPTY;
        return solutions;
    }

    bool can_remove(int index) {
        auto data_backup = this->data;
        data_backup[index] = EMPTY;
        Problem prob(data_backup, lim);
        int solutions = prob.count_solutions(0);
        return solutions > 0;
    }

    void fill_holes() {
        auto avaliable = shuffle(range<int>(0, data.size()));
        for (int index : avaliable)
            if (can_remove(index))
                data[index] = EMPTY;
    }
};

int main (int argc, char * argv[]) {
    srand(time(NULL));
   int size { 5 }, lim { 3 };
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <size> <lim>" << endl;
        return 1;
    }
    std::istringstream(argv[1]) >> size;
    std::istringstream(argv[2]) >> lim;
    std::cout << size << ' ' << lim << endl;

    Problem prob(std::string(size, EMPTY), lim);
    prob.solve(0);
    std::cout << prob.data << endl;
    prob.fill_holes();
    std::cout << prob.data << endl;
}