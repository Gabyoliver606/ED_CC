#include <iostream>
#include <vector>

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
    int size;

    cin >> size;
    vector <string> base(size,"");
    for (int i = 0; i < size; i++) 
        cin >> base[i];
    
    cin >> size;
    vector <string> consulta(size,"");
    for (int i = 0; i < size; i++) 
        cin >> consulta[i];

    vector <int> result = matchingStrings(base, consulta);
    for (int i = 0; i < result.size(); i++) 
        cout << result[i] << endl;
    return 0;

}