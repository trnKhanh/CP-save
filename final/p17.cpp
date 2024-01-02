
#include <iostream>
using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

void solve() {
  int n;
  cin >> n;

  for (int mask = 1; mask < (1<<9); ++mask) {
    int num = 0;

    for (int i = 8; i >= 0; --i) {
      int d = (mask>>i) & 1;
      num = num * 10 + d;
    }

    if (num % n == 0) {
      cout << num << "\n";
      return;
    }
  }
}
