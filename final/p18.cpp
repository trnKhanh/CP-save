#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

void solve() {
  int n;
  cin >> n;
  int sorted = 0;
  int revSorted = 0;
  for (int i = 1; i <= n; ++i) {
    sorted = sorted * 10 + i;
    revSorted = revSorted * 10 + (n-i+1);
  }
  vector<int> d(revSorted - sorted + 1, -1); 
#define d(i) d[i - sorted]

  int num = 0;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    num = num * 10 + x;
  }

  queue<int> q;
  q.push(num);
  d(num) = 0;
  
  while (!q.empty()) {
    int x = q.front(); q.pop();

    for (int i = 1; i < n; ++i) {
      int cur = x;
      int n2 = 0;
      int cof = 1;
      for (int j = n-1; j > i; --j) {
        n2 += cof * (cur % 10);
        cur /= 10;
        cof *= 10;
      }
      int n1 = 0;
      while (cur) {
        n1 = n1 * 10 + cur % 10;
        cur /= 10;
      }
      int newNum = n1 * cof + n2;
      if (d(newNum) == -1) {
        d(newNum) = d(x) + 1;
        if (newNum == sorted) {
          cout << d(newNum) << endl;
          return;
        }
        q.push(newNum);
      }
    }
  }
}
