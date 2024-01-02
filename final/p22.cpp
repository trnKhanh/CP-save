#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

int n, m, t = 0;
vector<vector<pair<int, int>> > adj;
vector<int> level, low, child, ans;

void dfs(int u, int p = -1) {
  child[u] = 1;
  level[u] = low[u] = t++;

  for (auto e: adj[u]) {
    int v = e.first;
    int id = e.second;
    if (v == p) 
      continue;
    if (level[v] == -1) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      child[u] += child[v];

      if (low[v] > level[u]) {
        ans[id] = child[v] * (n - child[v]);
      } else {
        ans[id] = 0;
      }

    } else {
      low[u] = min(low[u], level[v]);
    }
    
  }
  --t;
}

void solve() {
  cin >> n >> m;

  adj.resize(n + 1);
  level.resize(n + 1, -1);
  low.resize(n + 1, -1);
  ans.resize(m);
  child.resize(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  
  dfs(1);
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << " ";
  }

  cout << endl;
}
