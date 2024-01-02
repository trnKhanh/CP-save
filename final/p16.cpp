#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

int n;
vector<vector<int> > adj;
int ans = 0;

int dfs(int u, int p = -1) {
  int child = 1;
  for (auto v: adj[u]) {
    if (p != v) {
      child += dfs(v, u);
    }
  }
  ans += (n - child) * child;
  return child;
}

void solve() {
  cin >> n;
  
  adj.resize(n + 1);

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1);

  cout << ans << "\n";
}
