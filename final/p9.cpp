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
  int n = a.size(), m = b.size();

  a = "$" + a;
  b = "$" + b;

  vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

  dp[0][0] = 1;

  for (int i = 0; i <= n; ++i) { 
    for (int j = 0; j <= m; ++j) {
      if (i == j && i == 0)
        continue;
      
      if (b[j] == '*') {
        if (i-1 >= 0)
          dp[i][j] |= (dp[i-1][j] & (a[i] == b[j-1]));
        dp[i][j] |= dp[i][j-2];
      } else if (b[j] == '.') {
        if (i-1 >= 0)
          dp[i][j] |= dp[i-1][j-1];
      } else {
        if (i-1 >= 0 && j-1 >= 0)
          dp[i][j] |= (dp[i-1][j-1] & (a[i] == b[j]));
      }
    }
  }

  if (dp[n][m]) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }
}
