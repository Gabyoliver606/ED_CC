#include <iostream>
#include <vector>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> result;
    for (auto query : queries) {
        int count = 0;
        for (auto string : strings) {
            if (string == query) {
                count++;
            }
        }
        result.push_back(count);
    }
    return result;
}

int main () {
    int strings_count;
    cin >> strings_count;
    vector<string> strings(strings_count);
    for (int i = 0; i < strings_count; i++) {
        cin >> strings[i];
    }
    int queries_count;
    cin >> queries_count;
    vector<string> queries(queries_count);
    for (int i = 0; i < queries_count; i++) {
        cin >> queries[i];
    }
    vector<int> result = matchingStrings(strings, queries);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    return 0;
}
