#include <iostream>
#include <vector>
using namespace std;
void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  solve();
}
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else 
    return gcd(b, a % b);
}


void solve() {
  int n, k;
  cin >> n >> k;
  
  vector<int> a(n);

  for (int i = 0; i < n; ++i) 
    cin >> a[i];

  vector<pair<int, int> > curSet;
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    vector<pair<int, int> > newSet;
    curSet.push_back({0, i});
    for (int j = 0; j < curSet.size(); ++j) {
      if (curSet[j].second <= i - k) 
        continue;
      
      int tmp = gcd(a[i], curSet[j].first);
      if (!newSet.empty() && newSet.back().first == tmp) {
        newSet.back().second = curSet[j].second;
        continue;
      }

      newSet.push_back({tmp, curSet[j].second});
    }
    curSet = newSet;
    if (i >= k - 1) {
      ans = max(ans, curSet[0].first);
    }
  }

  cout << ans << "\n";
}
