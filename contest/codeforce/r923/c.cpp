#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {
    int n, m, k; std::cin >> n >> m >> k;
    std::vector<int> v(k+1);
    for (int i = 0; i < n; ++i) {
      int x; std::cin >> x;
      if (x > k) { continue; }
      v[x] |= 0b1;
    }
    for (int i = 0; i < m; ++i) {
      int x; std::cin >> x;
      if (x > k) { continue; }
      v[x] |= 0b10;
    }
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= k; ++i) {
      if (v[i] == 0) { c1 = k; }
      else if (v[i] == 0b1) { c1++; }
      else if (v[i] == 0b10) { c2++; }
    }
    if (c1*2 <= k && c2*2 <= k) { std::cout << "YES"; }
    else { std::cout << "NO"; }
    NL;
  }

  return 0;
}
