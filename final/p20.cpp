#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
}

void solve() {
  int n = 0;
  int y;
  vector<int> a;
  string s;
  getline(cin, s);
  cin >> y;

  istringstream is(s);

  while (!is.eof()) {
    int x;
    is >> x;
    a.push_back(x);
  }

  n = a.size();
  vector<int> p(n + 1);
  p[0] = 1;
  for (int i = 1; i <= n; ++i)
    p[i] = p[i - 1] * i;

  int k = 0;
  vector<int> inAns(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int d = 1; d < a[i]; ++d) {
      if (!inAns[d]) {
        k += p[n - i - 1];
      }
    }
    inAns[a[i]] = 1;
  }

  cout << k + 1 << "\n";

  inAns.assign(n + 1, 0);
  --y;

  for (int i = 0; i < n; ++i) {
    int d = 1;
    for (; d < n; ++d) {
      if (!inAns[d]) {
        if (y - p[n - i - 1] >= 0) {
          y -= p[n - i - 1];
        } else {
          break;
        }
      }
    }
    inAns[d] = 1;
    cout << d << " ";
  }

  cout << "\n";
}
