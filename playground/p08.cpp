#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v;
    int sum = 0; int x;
    orep(i, 0, n) {
      std::cin >> x;
      if (!x) { continue; }
      sum ^= x; v.emplace_back(x);
    }

    bool f = 0;

    for(auto y : v) { if (y != v.back()) { f = 1; } }

    std::cout << (f || sum ? "YES" : "NO"); NL;
  }

  return 0;
}
