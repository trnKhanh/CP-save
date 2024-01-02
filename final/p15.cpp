#include <math.h>
#include <iostream>

using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  solve();
}

long double dis(long double x1, long double y1, long double x2, long double y2) {
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void solve() {
  long double x1, x2, y1, y2, R;

  cin >> x1 >> y1 >> x2 >> y2 >> R;

  long double h = dis(x1, y1, x2, y2) / 2;

  long double angle = acos(h / R);

  long double fanArea = angle * R * R;

  long double triangleArea = sqrt(R*R - h*h) * h;

  long double intersect = (fanArea - triangleArea) * 2;

  long double res = M_PI * R * R * 2 - intersect;

  cout << res << "\n";
}
