#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vet[i];
    }
    
    vector <int> rvet(n);
    for (int i = 0; i < n; i++) {
        rvet[i] = vet[n - i - 1];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += rvet[i];
    }
    int mult = 1;
    for (int i = 0; i < n; i++) {
        mult *= rvet[i];
    }
    int max = rvet[0];
    for (int i = 0; i < n; i++) {
        if (rvet[i] > max) {
            max = rvet[i];
        }
    }
    int min = rvet[0];
    for (int i = 0; i < n; i++) {
        if (rvet[i] < min) {
            min = rvet[i];
        }
    }
    stringstream ss;
    for(int i = 0; i < n; i++) {
        ss << rvet[i];
    }
    string s = ss.str();
    sort(rvet.begin(), rvet.end());
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (rvet[i] == min) {
            pos = i;
        }
    }
    cout << sum << endl;
    cout << mult << endl;
    cout << max << endl;
    cout << min << endl;
    cout << s << endl;
    cout << pos << endl;
    return 0;
}
