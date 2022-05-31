#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    queue <char> time;
    int time1, time2;
    
    for ( int i = 0; i < argc; i++ ) {
        time.push(argv[i][0]);
    }

    for (int i = 0; i < 15; i++) {
        cin >> time1 >> time2;
        while (time1 != time2) {
            if (time1 < time2) {
                time.push(time.front());
                time.pop();
            } else {
                time.pop();
            }
        }
    }
    cout << time.front();
    return 0;
}
