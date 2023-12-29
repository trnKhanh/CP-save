#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

void solve() {
  int n;
  cin >> n;
  cin.ignore();
  
  vector<vector<int> > a(n);

  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    
    istringstream is(s);
    while (!is.eof())
    {
      int x;
      is >> x;
      a[i].push_back(x);
    }
  }

  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > q;

  vector<int> ptr(n, 0);

  for (int i = 0; i < n; ++i) {
    q.push({a[i][0], i});
  }

  vector<int> sorted;

  while (!q.empty()) {
    int id = q.top().second;
    q.pop();
    
    sorted.push_back(a[id][ptr[id]++]);

    if (ptr[id] < a[id].size())
      q.push({a[id][ptr[id]], id});
  }

  for (auto x: sorted) {
    cout << x << " ";
  }

  cout << endl;
   
}
