#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}
typedef pair<int, int> point;

int cw(point a, point b, point c) {
  return (b.first - a.first) * (b.second + a.second) \
        + (c.first - b.first) * (c.second + b.second) \
        + (a.first - c.first) * (a.second + c.second) > 0;
}

void solve() {
  int n;
  cin >> n;

  vector<pair<int, int> > pts(n);
  vector<int> ids(n);
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].first >> pts[i].second;
    ids[i] = i;
  }

  sort(ids.begin() + 1, ids.end(), [&](int a, int b) {
    return cw(pts[0], pts[a], pts[b]);
  });

  cout << ids[0] + 1 << " " << ids[(n-1)/2 + 1] + 1 << endl;
}
