#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

void solve() {
  int n;
  cin >> n;

  vector<pair<int, int> > ans;

  for (int i = 1; i * i <= n; ++i) {
    int tmp = n - i*i;
    int sq = sqrt(tmp);
    
    if (sq * sq == tmp) {
      int x = 1, y = 1;
      cout << x << " " << y << endl;
      x += i; y += sq;
      cout << x << " " << y << endl;
      x += sq; y -= i;
      cout << x << " " << y << endl;
      x -= i; y -= sq;
      cout << x << " " << y << endl;
      return;
    }
  }

  cout << "Impossible\n";
}
