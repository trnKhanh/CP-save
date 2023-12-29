#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

int abs(int a) {
  return a < 0 ? -a: a;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);

  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    b[i] *= -1;
  }
 
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = 1e9;
  int x = -1, y = -1;

  for (int i = 0; i < n; ++i) {
    int lw = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    
    if (lw < b.size()) {
      if (ans > abs(b[lw] - a[i])){
        ans = abs(b[lw] - a[i]);
        x = i;
        y = lw;
      }
    }
    if (ans > abs(b[lw-1] - a[i])){
      ans = abs(b[lw-1] - a[i]);
      x = i;
      y = lw-1;
    }
  }

  cout << x << " " << y << "\n";
}
