#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}
int _abs(int a) {
  return a < 0 ? -a : a;
}

int n, c;
vector<int> h;
int isEffected(int d, int cur,int i) {
  return h[i] > d + _abs(cur - i);
}

int getSum(int n) {
  return (n + 1) * n / 2;
}
int minL, minR;

int getLeft(int d, int i) {
  return d + i + 1 - minL;
}
int getRight(int d, int i) {
  return d - i + 1 - minR;
}

vector<int> L, R;
vector<int> first, last;
void calL() {
  L.resize(n);
  first.resize(2 * n, -1);
  
  minL = 1e9;
  for (int i = 0; i < n; ++i) {
    L[i] = h[i] + i;
    minL = min(minL, L[i]);
  }

  for (int i = 0; i < n; ++i) {
    L[i] -= minL;
  }

  for (int i = 0; i < n; ++i) {
    if (first[L[i]] == -1)  {
      first[L[i]] = i;
    }
  }
}
void calR() {
  R.resize(n);
  last.resize(2 * n, -1);
  
  minR = 1e9;
  for (int i = 0; i < n; ++i) {
    R[i] = h[i] - i;
    minR = min(minR, R[i]);
  }

  for (int i = 0; i < n; ++i) {
    R[i] -= minR;
  }

  for (int i = n - 1; i >= 0; --i) {
    if (last[R[i]] == -1)  {
      last[R[i]] = i;
    }
  }
}



void solve() {
  cin >> n >> c;
  h.resize(n+1);
  int d = 1e9;

  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    d = min(d, h[i]);
  }
  --d;

  vector<int> pre(n+1, 0);
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i-1] + h[i];
  }

  calR();
  calL();

  int l = 1, r = 1;

  for (int i = 1 ;i <= n; ++i) {
    while (1) {
      int left = getLeft(d, i);
      int right = getRight(d, i);
      int l = left < 0 ? 1 : first[left];
      int r = right < 0 ? n: last[right];

      if (l == -1 || l > i) 
        l = i;
      if (r == -1 || r < i) 
        r = i;

      int costNeeded = pre[r] - pre[l-1] - (d * (r - l + 1) + getSum(i-l) + getSum(r-i));
      if (costNeeded <= c) {
        if (l == 1 && r == n) {
          d -= (c - costNeeded) / n;
        }
        --d;
      } else {
        break;
      }
    }
    
  }
  cout << d + 1 << endl;
}
