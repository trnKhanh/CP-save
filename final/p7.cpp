#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

void solve() {
  int n;
  cin >> n;

  vector<int> h(n);
  
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  vector<int> suf(n, 0), pre(n, 0);

  pre[0] = h[0];
  for (int i = 1; i < n; ++i) {
    pre[i] = max(pre[i-1], h[i]);
  }

  suf[n-1] = h[n-1];
  for (int i = n-1; i >= 0; --i) {
    suf[i] = max(suf[i+1], h[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) 
    ans += min(pre[i], suf[i]) - h[i];

  cout << ans << "\n";
}
