#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}
typedef pair<int, int> point;
typedef long long ll;

ll _abs(ll a) {
  return a > 0 ? a : -a;
}

ll getArea(point a, point b, point c) {
  ll res = (ll)(b.first - a.first) * (b.second + a.second) \
        + (ll)(c.first - b.first) * (c.second + b.second) \
        + (ll)(a.first - c.first) * (a.second + c.second);

  return res > 0 ? res : -res;
}

ll getArea(vector<point> &pts) {
  ll res = 0;
  int n = pts.size();

  for (int i = 1; i + 1 < n; ++i) {
    res += getArea(pts[0], pts[i], pts[(i+1)%n]);
  }

  return res;
}

void solve() {
  int n;
  cin >> n;
  
  vector<point> pts(n);
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].first >> pts[i].second;
  }

  ll area = getArea(pts);

  int i = 0, j = 1;
  ll curArea = 0;
  ll ans = 1e18;
  ll x, y;

  for (; i < n; ++i) {
    while (j + 1 != i) {
      ll nextArea = curArea + getArea(pts[i], pts[j], pts[(j+1)%n]);

      if (_abs(area - 2 * nextArea) <= _abs(area - 2 * curArea)) {
        ++j;
        j %= n;
        curArea = nextArea;
      } else {
        break;
      }
    }

    if (ans > _abs(area - 2 * curArea)) {
      ans = _abs(area - 2 * curArea);
      x = i;
      y = j;
    }

    curArea -= getArea(pts[i], pts[(i+1)%n], pts[j]);
  }

  cout << x + 1 << " " << y + 1 << "\n";
}

