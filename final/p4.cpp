#include <iostream>
#include <vector>

using namespace std;

void solve();

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
}

int merge(vector<int> &a, int l, int r) {
  if (l == r) {
    return 0;
  }
  int mid = (l + r) >> 1;
  
  int res = merge(a, l, mid) + merge(a, mid+1, r);

  vector<int> sorted;

  int j = mid + 1;
  
  for (int i = l; i <= mid; ++i) {
    while (j <= r && a[j] < a[i]) {
      res += (mid - i + 1);
      sorted.push_back(a[j++]);
    }
    sorted.push_back(a[i]);
  }

  for (; j <= r; ++j) {
    sorted.push_back(a[j]);
  }

  for (int i = l; i <= r; ++i) {
    a[i] = sorted[i-l];
  }

  return res;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = merge(a, 0, n-1);
  cout << ans << "\n";
}

