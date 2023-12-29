#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

void solve() {
  int k, n, m;
  cin >> k >> n >> m;
  
  vector<pair<int, int> > a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a.rbegin(), a.rend());

  int s = 0;
  set<pair<int, int> > diffs, A, B;

  for (int i = 0; i < n + m; ++i) {
    A.insert({a[i].first, i});
    diffs.insert({a[i].second - a[i].first, i});
    s += a[i].first;
  }

  for (int i = n + m; i < k; ++i) {
    B.insert({a[i].second, i});
  }
  for (int i = 0; i < m; ++i) {
    int idA = (*A.begin()).second;
    int idB = (*B.rbegin()).second;

    if ((a[idB].second - a[idA].first) >= (*diffs.rbegin()).first) {
      s += a[idB].second - a[idA].first;

      A.erase(A.find({a[idA].first, idA}));
      B.erase(B.find({a[idB].second, idB}));
      diffs.erase(diffs.find({a[idA].second - a[idA].first, idA}));
      diffs.erase(diffs.find({a[idB].second - a[idB].first, idB}));
    } else {
      s += (*diffs.rbegin()).first;

      int id = (*diffs.rbegin()).second;
      A.erase(A.find({a[id].first, id}));
      diffs.erase(diffs.find({a[id].second - a[id].first, id}));
    }
  }

  cout << s << endl;
}
