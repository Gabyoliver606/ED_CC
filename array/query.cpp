#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector <int> matchingStrings(vector <string> strings, vector <string> queries) {
    vector <int> result;
    int size = queries.size();
    int size2 = strings.size();
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size2; j++) {
            if (queries[i] == strings[j]) {
                count++;
            }
        }
        result.push_back(count);
        count = 0;
    }
    return result;
}

int main () {
    vector <string> strings;
    vector <string> queries;
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        string x;
        while(ss >> x)
            strings.push_back(x);
    }
    getline(cin, line);
    stringstream ss(line);
    string x;
    while(ss >> x)
        queries.push_back(x);
    vector <int> result = matchingStrings(strings, queries);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;

}