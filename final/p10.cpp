#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > a(n, vector<int> (m));
  vector<vector<int> > dp(n, vector<int> (m, 1));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int tmp = 1e9;

      if (i-1>=0 && a[i][j] == a[i-1][j]) {
        tmp = min(tmp, dp[i-1][j]);
      } else {
        tmp = 0;
      }

      if (j-1>=0 && a[i][j] == a[i][j-1]) {
        tmp = min(tmp, dp[i][j-1]);
      } else {
        tmp = 0;
      }

      if (i-1>=0 && j-1>=0 && a[i][j] == a[i-1][j-1]) {
        tmp = min(tmp, dp[i-1][j-1]);
      } else {
        tmp = 0;
      }
      
      dp[i][j] = tmp + 1;
      ans = max(ans, dp[i][j]);
    }
  }
  
  cout << ans << "\n";
}
