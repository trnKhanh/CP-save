#include <iostream>
#include <vector>

using namespace std;

void solve();

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
}

void solve() {
  int n;
  cin >> n;

  vector<int> isPrime(2 * n, 1);
  vector<int> cnt(2 * n, 0);
  isPrime[0] = isPrime[1] = 0;
  int ans = 0;
  for (int i = 2; i < 2 * n; ++i) {
    cnt[i] = cnt[i-1] + (i != 2 ? isPrime[i] : 0);

    if (isPrime[i]) {

      for (int j = i * 2; j < 2 * n; j += i) {
        isPrime[j] = 0;
      }
    }
  }

  for (int i = 3; i < 2 * n; ++i) {
    if (isPrime[i]) {
      int tmp = min(i, 2 * n - i);
      ans += cnt[tmp];
    }
  }
  if (n >= 2)
    ++ans;

  
  cout << ans << endl;
}
