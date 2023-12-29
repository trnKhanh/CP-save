#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}
int cnt = 0;
void bt(int n, int id, vector<int> &cols, bool visual=false) {
  if (n == id) {
    ++cnt;
    if (visual) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (cols[j] == i) 
            cout << "Q";
          else 
            cout << ".";
        }
        cout << "\n";
      }
      cout << "\n";
    }
    return;
  }

  for (int i = 0; i < n; ++i) {
    int valid = 1;
    for (int j = 0; j < cols.size(); ++j) {
      if (cols[j] == i || cols[j] - j == i - id || cols[j] + j == i + id) {
        valid = 0;
        break;
      }
    }
    if (!valid)
      continue;
    cols.push_back(i);
    bt(n, id+1, cols, visual);
    cols.pop_back();
  }

}

void solve() {
  int n; 
  cin >> n;

  vector<int> cols;
  cnt = 0;
  bt(n, 0, cols);
  cout << cnt << endl;
  bt(n, 0, cols, true);
}

