#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

lli oil[1000005];
lli dis[1000005];
queue <int> q;
long unsigned int n;

int main (void) {
   long unsigned int i;
    cin >> n;

    for (i = 0; i < n; i++)
    cin >> oil[i] >> dis[i];

  while (!q.empty())
    q.pop();

    q.push(0);

  lli sum = 0;
  int id = 0;

  while (q.size() < n) {
    id = q.back();
    sum += get(id);
    while (sum < 0 && !q.empty())
      q.pop();
    if (q.empty())
      sum = 0;
    q.push((id + 1) % n);
  }
    cout << sum << endl;
  return 0;
}