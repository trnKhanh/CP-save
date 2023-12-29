#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

void solve() {
  string a, b;
  cin >> a >> b;
  a = b + a;

  int n = a.size(), m = b.size();
  vector<int> l(a.size() + 1);
  
  l[0] = 0;

  int i = 1;
  int cur = 0;
  while (i < n) {
    if (a[i] == a[cur]) {
      l[i++] = ++cur;
    } else {
      if (cur-1 >= 0) 
        cur = l[cur-1];
      else 
        l[i++] = cur;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (l[i] >= m) {
      cout << i - (2 * m - 1) << " ";
    }
  }
}
